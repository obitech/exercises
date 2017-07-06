/*	1) Create an permutation from 0 to n 
* 	2) Shift the values through the array until the value at index 0 = 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void seedInit();
static int* randArray(int);
static void printArray(int*, int);
static void algo(int*, int);

int main() {
	seedInit();

	int var_size = 0;
	int* array;

	printf("Until which natural number do you want to permutate?\n> ");
	scanf("%d", &var_size);

	array = randArray(var_size);
	
	printf("Initial array:\n");
	printArray(array, var_size);

	printf("Applying algorithm...\n");
	algo(array, var_size);

	printf("Finished array:\n");
	printArray(array, var_size);
}

// Shift numbers in array until a[0] = 1
void algo(int* array, int size) {
	int temp = 0;
	
	while(array[0] != 1) {
		temp = array[0];
		for (int i = 0; i < size - 1; i++) {
			array[i] = array[i + 1];
		}
		array[size - 1] = temp;
	}
}

// Create an array from 0..n, randomize it
int* randArray(int var_size) {
	int* array = (int*) malloc(var_size * sizeof(int));
	int j = 0, temp = 0;
	
	// Creating array with ordered set numbers
	for (int i = 0; i < var_size; i++) {
		array[i] = i;
	}

	// Shuffle array
	for (int i = var_size - 1; i >= 0; i--) {
		j = rand() % (i + 1);
		temp = array[j];
		array[j] = array[i];
		array[i] = temp;
	}

	return array;
}

// Randomizing seed
void seedInit() {
	srand(time(0));
	rand();
}

// Print array
void printArray(int* array, int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf("%d", array[i]);

		if (i != size - 1) {
			printf(",");
		}
	}
	printf("]\n");
}
