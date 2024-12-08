#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

static void die(const char *s) {perror(s); exit(1);}

int main() {
	
	while (1) {
		char buffer[32];
		
		//check if child processes have been terminated
		pid_t terminated_child;
		do {
			terminated_child = waitpid((pid_t)-1, NULL, WNOHANG);
			if (terminated_child > 0){
				printf("[pid=%d] mdb-lookup-server terminated\n", terminated_child);
			}
		} while (terminated_child > 0);

		//prompt for port number while handling error inputs
		printf("port number: ");
		fflush(stdout);

		if (fgets(buffer, sizeof(buffer), stdin) == NULL){
			continue;
		}

		if (buffer[0] == '\n'){
			continue;
		}

		int portNumber = atoi(buffer);
		if (portNumber <= 0) {
			continue;
		}

		//fork child process
		pid_t pid = fork();

		if (pid < 0) {
			die("fork failed");
		} else if (pid == 0) {
			//child process
			fprintf(stderr, "[pid=%d] mdb-lookup-server started on port %d\n", (int)getpid(), portNumber);
			char arrayString[16];
			sprintf(arrayString, "%d", portNumber);
			execl("./mdb-lookup-server-nc.sh", "mdb-lookup-server-nc.sh", arrayString, (char *)0);
			die("execl failed");
		} else {
			//parent process
			printf("An instance of mdb-lookup-server has started on pid %d and port %d.\n", pid, portNumber);
		}
	}

	return 0;
}
