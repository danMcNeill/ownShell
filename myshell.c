#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


int main() {

	char line[1024];
	int pid, i, count, begin, end;
	char* args[64];
	char* tempBegin = NULL;
	while(1) {
		printf("Hello!!>");
		if(!fgets(line, 1023, stdin)) {
			break;
		}
		if(strcmp(line, "exit\n") == 0)
			break;

/*break up string here */
		i = 0;
		count = 1;

		args[0] = line;

		while(line[i] != '\0') { /* while more commands */
			while(line[i] != ' ' && line[i] != '\n' && line[i] != '\t') {
				i++;
			}

			while(line[i] == ' ' || line[i] == '\n' || line[i] == '\t') {
				line[i] = '\0';
				i++;
			}
			if(line[i] == '\0') break;
			args[count++] = &(line[i++]);



			/*if(line[i] == ' ' || line[i] == '\n') {
				line[i] = '\0';
				i++;
				if(line[i] == '\0') break;
				*args++ = line;
				continue;
			}

			i++;*/
		}

		args[count] = '\0';
		
/* args set at this point*/



		for(i=0; i<strlen(line); i++) {
			if(line[i] == '\n')
				line[i] = '\0';
		}
		int x = 0;
		pid = fork();
		if(pid == 0) { /* this is the child */
			execvp(*args, args);
			fprintf(stderr, "Hello!!: %s\n", strerror(errno));
			exit(errno);
		}
		else {
			wait(NULL);
		}
	}

	return 0;

}

