#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static char **duplicateArgs(int argc, char **argv)
{
	//allocate memory for array
	char **array = malloc((argc + 1) * sizeof(char*));
	if (array == NULL){
		perror("malloc returned NULL");
		exit(1);
	}

	//allocate memory for each string of argument in array
	for (int i = 0; i < argc; i++) {
		array[i] = malloc(strlen(argv[i]) + 1);
		if (array[i] == NULL) {
			perror("malloc returned NULL");
			exit(1);
		}
		
		//Copy and capitalize each char
		int j = 0;
		while (argv[i][j] != '\0') {
			array[i][j] = toupper(argv[i][j]);
			j++;	
		}

		//add null terminator back
		array[i][j] = '\0';

	}
	return array;
}

static void freeDuplicatedArgs(char **copy)
{
	for (int i = 0; copy[i] != NULL; i++) {
		free(copy[i]); //free each argument

	}
	free(copy); //free array
}


/*
 * DO NOT MODIFY main().
 */
int main(int argc, char **argv)
{
    if (argc <= 1)
        return 1;

    char **copy = duplicateArgs(argc, argv);
    char **p = copy;

    argv++;
    p++;
    while (*argv) {
        printf("%s %s\n", *argv++, *p++);
    }

    freeDuplicatedArgs(copy);

    return 0;
}
