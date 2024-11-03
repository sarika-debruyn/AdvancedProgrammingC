#include <stdio.h>
#include <string.h>
#include "mylist.h"

//function to print each input command
void print(void *data) {
	printf("%s\n", (char *)data);
}

int main(int argc, char **argv){
	//initialize string list
	struct List stringList;
	initList(&stringList); 

	//Add command-line arguments to string list
	for (int i = 1; i < argc; i++) {
		addFront(&stringList, argv[i]);
	}
	//print list in reverse
	traverseList(&stringList, &print);
	printf("\n");

	//check for 'dude' in list
	struct Node *currentNode = stringList.head;
	int foundDude = 0;

	while (currentNode != NULL) {
		if (strcmp((char *)currentNode->data, "dude") == 0) {
			foundDude = 1;
		}
		currentNode = currentNode->next;
	}
	
	if (foundDude) {
		printf("dude found\n");
	} else {
		printf("dude not found\n");
	}
	
	//free up memory
	removeAllNodes(&stringList);
	return 0;
}
