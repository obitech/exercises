#include <stdio.h>
#include <stdlib.h>

// Input integer
int getInt() {
	int z;
	scanf("%d", &z);
	return z;
}

// Create randomized array from 0 to size
int* createRandArray(int size) {
	int* array = (int*) malloc(size * sizeof(int));
	int j = 0, temp = 0;
	
	// Creating array with ordered set numbers
	for (int i = 0; i < size; i++) {
		array[i] = i;
	}

	// Shuffle array
	for (int i = size - 1; i >= 0; i--) {
		j = rand() % (i + 1);
		temp = array[j];
		array[j] = array[i];
		array[i] = temp;
	}

	return array;
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

// Sort via selection sort and return pointer to start of sorted array
int* sortArray(int* array, int size) {
	int min, pos, temp;
	int swapping = 0;

	// We'll only be working in our subarray
	int* subarray = malloc(size * sizeof(int));
	subarray = array;

	// Iterating over whole array
	for (int i = 0; i < size; i++) {
		min = subarray[i];

		// Do we have a value higher than the first in our array?
		for (int j = i + 1; j < size; j++) {
			if (subarray[j] < min) {
				min = subarray[j]; 
				pos = j;
				swapping = 1;
			}
		}

		// Swap positions with current comparing element and smallest element
		if (swapping) {
			temp = subarray[pos];
			subarray[pos] = subarray[i];
			subarray[i] = temp;
		}
	}

	return subarray;
}

int main() {
	int *start_array, *sorted_array;
	int size = 0;

	printf("How many numbers should your array have?\n> ");
	size = getInt();

	start_array = createRandArray(size);
	printf("Start array: ");
	printArray(start_array, size);

	sorted_array = sortArray(start_array, size);
	printf("Sorted array: ");
	printArray(sorted_array, size);

}