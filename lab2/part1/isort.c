#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This function sorts an integer array
 * using selection sort. It takes in the
 * parameters: array and array's size 
 */
void selection_sort(int arr[], int n, int ascending){
	for (int i = 0; i < n - 1; i++){
		int min_index = i;

		for (int j = i + 1; j < n; j++) {
			if (ascending) { 
				if (arr[j] < arr[min_index]) {
					min_index = j;
				}
			} else { //descending
				if (arr[j] > arr[min_index]){
					min_index = j;
				}
			}
		}

		int temp = arr[min_index];
		arr[min_index] = arr[i];
		arr[i] = temp;
	}
}

/* This function uses the selection_sort
 * function and begin points to the 1st element
 * of the array. 
 * end points to the one past the last element of
 * the array.
 * If ascending is 1, the array will be sorted in ascending order.
 * If ascending is 0, the array will be sorted in descending order.
 */
void sort_integer_array(int *begin, int *end, int ascending){
	int size = end - begin;
		
	selection_sort(begin, size, ascending);
}

int main(){
		
	int size;

	printf("Insert the size of the array: ");
	scanf("%d", &size);
	
	int *p =  malloc(size*sizeof(int)); //Allocate memory
	if (p == NULL) {	
		perror("malloc returned NULL");
		exit(1);
	}

	int *array = p;

	//Seed the random generator
	srandom(time(NULL));
	
	//Fill array with random numbers
	for (int i = 0; i < size; i++) {
		array[i] = random() % 100;
	}

	//Print out original
	printf("original: ");
	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	printf("ascending: ");
	//array points to begin, array + size points to end
	sort_integer_array(array, array + size, 1); 
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	printf("descending: ");
	sort_integer_array(array, array + size, 0); 
	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	
	free(array); //free dynamically allocated memory
	return 0;	
}	
