
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "mylist.h"
#include "mdb.h"

#define KeyMax 5

static void die(const char *message)
{
    perror(message);
    exit(1); 
}

int main(int argc, char **argv){

	if (argc != 3) {
		fprintf(stderr, "usage: %s <server-port>\n", argv[0]);
		exit(1);
       	}
	
	char *filename = argv[1];
	unsigned short port = atoi(argv[2]);
	
	// ignore SIGPIPE 
	if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		die("signal() failed");

	//Create a listening socket
	int servsock;
	if ((servsock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	    die("socket failed");
	
	//Construct local address structure
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(port);

	//Bind to local address
	if (bind(servsock, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
	    die("bind failed");

	//Listen for incoming connections
	if (listen(servsock, 5) < 0)
	    die("listen failed");

	int clntsock;
	socklen_t clntlen;
	struct sockaddr_in clntaddr;

	while (1) {

		//Accept incoming connection
		fprintf(stderr, "waiting for client...");
		clntlen = sizeof(clntaddr);

		if ((clntsock = accept(servsock, (struct sockaddr *) &clntaddr, &clntlen)) < 0){
			die("accept failed");
		}
		fprintf(stderr, "client ip: %s\n", inet_ntoa(clntaddr.sin_addr));

		FILE *fp = fopen(filename, "rb");
		if (fp == NULL){
			close(clntsock);
			die(filename);
		}

		// read all records into memory
		struct List list;
		initList(&list);
		int loaded = loadmdb(fp, &list);
		fclose(fp);
		if (loaded < 0){
			close(clntsock);
			die("loadmdb failed");
		}

		FILE *input = fdopen(clntsock, "r");
		if (input == NULL){
			close(clntsock);
			traverseList(&list, &free);
			removeAllNodes(&list);
			die("fdopen failed");
		}

		char line[1000];
		char key[KeyMax + 1];

		while (fgets(line, sizeof(line), input) != NULL) {
			// must null-terminate the string manually after strncpy().
			strncpy(key, line, sizeof(key) - 1);
			key[sizeof(key) - 1] = '\0';

			// if newline is there, remove it.
			size_t last = strlen(key) - 1;
			if (key[last] == '\n')
			    key[last] = '\0';

			// traverse the list, printing out the matching records
			struct Node *node = list.head;
			int recNo = 1;
			while (node) {
				struct MdbRec *rec = (struct MdbRec *)node->data;
				if (strstr(rec->name, key) || strstr(rec->msg, key)) {
					char message[1000];
					int message_len = snprintf(message, sizeof(message), "%4d: {%s} said {%s}\n", 
							recNo, rec->name, rec->msg);
					if (send(clntsock, message, message_len, 0) != message_len) {
						fprintf(stderr, "ERR: send failed\n");
						break;
					}
				}
				node = node->next;
				recNo++;
			}
		
			const char *eof = "\n";
			if (send(clntsock, eof, strlen(eof), 0) <0){
				fclose(input);
				close(clntsock);
				traverseList(&list, &free);
				removeAllNodes(&list);
				die("send size failed");
			}
		}
		// see if fgets() produced error
		if (ferror(input)){
			fclose(input);
			close(clntsock);	
			die("input");
		}

			
		// clean up and quit
		fclose(input);
		close(clntsock);
		traverseList(&list, &free);
		removeAllNodes(&list);

		
	}
	close(servsock);	

	return 0;
	
}
