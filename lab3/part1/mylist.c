#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mylist.h"

/*
 * Create a node that holds the given data pointer,
 * and add the node to the front of the list.
 * It returns the newly created node on success and NULL on failure.
 */
struct Node *addFront(struct List *list, void *data){
        struct Node *node = NULL;
        node = (struct Node *)malloc(sizeof(struct Node));
        if (node == NULL){
                perror("malloc returned NULL");
                return NULL;
        }
        node->data = data;
        node->next = list->head;//add to front of list
        list->head = node;
        return node;
}


/*
 * Traverse the list, calling f() with each data item.
 */
void traverseList(struct List *list, void (*f)(void *)){
        struct Node *node = list->head; //initialize at beginning of list
        while (node) {
                f(node->data);
                node = node->next; //move current node to next node
        }
}


/*
 * Traverse the list, comparing each data item with 'dataSought' using
 * 'compar' function.  ('compar' returns 0 if the data pointed to by
 * the two parameters are equal, non-zero value otherwise.)
 *
 * Returns the first node containing the matching data,
 * NULL if not found.
 */
struct Node *findNode(struct List *list, const void *dataSought,
                int (*compar)(const void *, const void *)){
        struct Node *node = list->head; //initialize start of list

        while (node) {
                if (compar(node->data, dataSought)==0) {
                        return node;
                }
                node = node->next; //iterate to next node
        }
        return NULL; //node not found
}


/*
 * Flip the sign of the double value pointed to by 'data' by
 * multiplying -1 to it and putting the result back into the memory
 * location.
 */
void flipSignDouble(void *data){
        double *new_data = data;
        *new_data = -(*new_data);
}


/*
 * Compare two double values pointed to by the two pointers.
 * Return 0 if they are the same value, 1 otherwise.
 */
int compareDouble(const void *data1, const void *data2){
        //cast void pointers to double pointers
        const double *value1 = (double *)data1;
        double *value2 = (double *)data2;
        //dereference to access the double values
        double d1 = *value1;
        double d2 = *value2;
        //compare double values
        if (d1==d2){
                return 0;
        } else{
                return 1;
        }
}


/*
 * Remove the first node from the list, deallocate the memory for the
 * node, and return the 'data' pointer that was stored in the node.
 * Returns NULL is the list is empty.
 */
void *popFront(struct List *list){
        struct Node *node = list->head;
        if (node == NULL) {
                return NULL;
        }

        list->head = node->next; //mode head to point to next node
        void *data = node->data; //retrieve data stored in this next node
        free(node);
        return data;
}


/*
 * Remove all nodes from the list, deallocating the memory for the
 * nodes.  You can implement this function using popFront().
 */
void removeAllNodes(struct List *list){
        while (!isEmptyList(list)){
                popFront(list);
        }
}


/*
 * Create a node that holds the given data pointer,
 * and add the node right after the node passed in as the 'prevNode'
 * parameter.  If 'prevNode' is NULL, this function is equivalent to
 * addFront().
 *
 * Note that prevNode, if not NULL, is assumed to be one of the nodes
 * in the given list.  The behavior of this function is undefined if
 * prevNode does not belong in the given list.
 *
 * Note that this function does not manage the lifetime of the object
 * pointed to by 'data'.
 *
 * It returns the newly created node on success and NULL on failure.
 */
struct Node *addAfter(struct List *list,
                struct Node *prevNode, void *data){
        struct Node* new_node = malloc(sizeof(struct Node));

        if (new_node == NULL) {
                perror("malloc returned NULL");
                return NULL;
        }

        new_node->data = data;

        if (prevNode == NULL){ //equivalent to addFront()
                new_node->next = list->head;
                list->head = new_node;
        } else { //if prevNode is inside list
                new_node->next = prevNode->next;
                prevNode->next = new_node;
        }
        return new_node;
}


/*
 * Reverse the list.
 *
 * Note that this function reverses the list purely by manipulating
 * pointers.  It does NOT call malloc directly or indirectly (which
 * means that it does not call addFront() or addAfter()).
 *
 * Implementation hint: keep track of 3 consecutive nodes (previous,
 * current, next) and move them along in a while loop.  
 * And at the end, prv will end up pointing to the first element of
 * the reversed list.  Don't forget to assign it to list->head.
 */
void reverseList(struct List *list){
        struct Node *prv = NULL;
        struct Node *cur = list->head;
        struct Node *nxt;

        while (cur){
                nxt = cur->next; //save the next node to nxt
                cur->next = prv; //reverse pointer of cur
                prv = cur; //move all pointers forward in list
                cur = nxt;
        }

        list->head = prv; //prv points to first element in list
}
