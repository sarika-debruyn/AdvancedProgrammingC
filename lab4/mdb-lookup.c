#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylist.h"
#include "mdb.h"

// function loads records from database file into linked list
void fillList(const char *filename, struct List *list){
        FILE *fp = fopen(filename, "rb");
        if (fp == NULL) {
                perror(filename);
                exit(1);
        }

	struct MdbRec record;
	struct Node *node = NULL;
	
	//read one record at a time
	while (fread(&record, sizeof(struct MdbRec), 1, fp) == 1) {
		struct MdbRec *newRecord = malloc(sizeof(struct MdbRec));
		if (newRecord == NULL) {
			perror("malloc returned NULL");
			fclose(fp);
			exit(1);
		}
		*newRecord = record;
		
		//maintain order of list
		if (node == NULL) {
			node = addAfter(list, NULL, newRecord);
		} else {
			node = addAfter(list, node, newRecord);
		}
	}
	fclose(fp);
}

// function prints records that match the search term
void printMatch(struct List *list, const char *search) {
	struct Node *node = list->head;
	int count = 1;
	
	while (node){
		struct MdbRec *record = (struct MdbRec *)node->data;

		if (strstr(record->name, search) || strstr(record->msg, search)) {
			printf("%4d: {%s} said {%s}\n", count, record->name, record->msg);
		}
		node = node->next;
		count++;
	}
}
	
//function to free memory
void freeList(struct List *list) {
	struct Node *current = list->head;
	while (current) {
		struct Node *next = current->next;
		free(current->data);
		free(current);
		current = next;
	}
	list->head = NULL;
}

int main(int argc, char **argv){
	// check command-line arguments
	if (argc != 2){
		fprintf(stderr, "%s\n", "usage: ncat <file_name>");
		exit(1);
	}
	
	//Initialize list
	struct List stringList;
	initList(&stringList);

	// load records from file into list	
	fillList(argv[1], &stringList);
	printf("lookup: ");
	fflush(stdout);
	char buff[1000];
	int max = 5;
	char search[6];

	// searches for search word
	while (fgets(buff, sizeof(buff), stdin)){
		//copy first 5 characters to search
		strncpy(search, buff, max);

		search[max] = '\0';

		//remove newline character
		if (buff[strlen(search) - 1] == '\n') {
			search[strlen(search) - 1] = '\0';
		}


		printMatch(&stringList, search);
		printf("lookup: ");
		fflush(stdout);
	}
	
	freeList(&stringList);
	return 0;
}
