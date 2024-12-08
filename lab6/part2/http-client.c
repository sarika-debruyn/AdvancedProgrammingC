#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

static void die(const char *message)
{
	perror(message);
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc != 4){
		fprintf(stderr, "usage: %s <host> <port> <path>\n", argv[0]);
		exit(1);
	}
	
	struct hostent *he;
	char *serverName = argv[1];
	unsigned short port = atoi(argv[2]);
	char *filepath = argv[3];
	
	// get server ip from server name
	if ((he = gethostbyname(serverName)) == NULL) {
		die("gethostbyname failed");
	}
	char *serverIP = inet_ntoa(*(struct in_addr *)he->h_addr);

	// create a socket
	int sock;
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		die("socket failed");

	// construct a server address structure
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr)); // must zero out the structure
	servaddr.sin_family      = AF_INET;
	servaddr.sin_port        = htons(port); // must be in network byte order
	servaddr.sin_addr.s_addr = inet_addr(serverIP);

	// Establish a TCP connection to the server
	if (connect(sock, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
		die("connect failed");
	
	// Read a line from HTTP and send it to the server
	char buf[1000];
	snprintf(buf, sizeof(buf),
		"GET %s HTTP/1.0\r\n"
		"Host: %s:%d\r\n"
		"\r\n",
		filepath, serverName, port);	

	size_t len = strlen(buf);
	if (send(sock, buf, len, 0) != len)
		die("send failed");

	FILE *input = fdopen(sock, "r");
	if (input == NULL) {
		die("failed to open sock");
	}

	// read and parse status line
	char statusLine[1000];
	if (fgets(statusLine, sizeof(statusLine), input) == NULL) {
		die("Error reading status line");
	}
	
	char http[50];
	int status;
	sscanf(statusLine, "%s %d", http, &status);
	
	// check HTTP version
	if (strcmp(http, "HTTP/1.0") != 0 && strcmp(http, "HTTP/1.1") != 0) {
		printf("%s", statusLine);
		fclose(input);
		close(sock);
		return 1;
	}

	// check that status code is 200
	if (status != 200) {
		printf("%s", statusLine);
		fclose(input);
		close(sock);
		return 1;
	}
	
	// Skip headers
	char headers[1000];
	while (fgets(headers, sizeof(headers), input) != NULL) {
		if (strcmp(headers, "\r\n") == 0) {
			break;
		}
	}
	
	// pick out filename from file path
	char *file = strrchr(filepath, '/');
	if (file) {
		file = file + 1;
	} 
	
	// read and save file content
	FILE *output = fopen(file, "wb");
	if (output == NULL) {
		die(file);
	}
	size_t n;
	char buffer[1000];
	while ((n = fread(buffer, 1, sizeof(buffer), input)) > 0){
			if (fwrite(buffer, 1, n, output) != n) {
				fclose(output);
				fclose(input);
				close(sock);
				return 1;
			}
		}
	fclose(output);
	fclose(input);
	close(sock);
	
	return 0;
}


