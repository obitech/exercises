/**
 * Create a custom sized (n by m) matrix whose random values are greater than then the previous i and j value 
 * (above and to the left). For example:
 * [7][10][15][..]
 * [8][11][16][..]
 * [..][..][..][..]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create a custom sized 2D Matrix
int** create2DMatrix(int n, int m) {
	int** array = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++) {
		array[i] = (int*)malloc(n * sizeof(int));
	}

	if (array) {
		printf("%dx%d matrix created.\n", n, m);
		return array;
	}
	else {
		printf("Error while allocating memory. NULL pointer returned\n");
		return NULL;
	}
}

// Fill array with 0
void zero2DMatrix(int** array, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			array[i][j] = 0;
		}
	}
}

void zeroCustom2DMatrix(int** array, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			array[i][j] = 0;
		}
	}
}

// Print Matrix
void printMatrix(int** array, int size) {
	printf("\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d/%d: %d\t", i, j, array[i][j]);
		}
		printf("\n");
	}
}

void printCustom2DMatrix(int** array, int n, int m) {
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
}

int getInt() {
	int z;
	scanf("%d", &z);
	return z;
}

// Randomizes seed
void seedInit() {
	srand(time(0));
	rand();
}

// Returns a random value between min and max
int getRandomValue(int min, int max) {
	//seedInit();

	return rand() % (max - min + 1) + min + 1;
}

// return lower value
int lowerValue(int a, int b) {
	return a < b ? a : b;
}

// Return higher value
int higherValue(int a, int b) {
	return a > b ? a : b;
}

int* createArray(int size) {
	int* array = (int*) malloc(size * sizeof(int));

	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}

	return array;
}

void fillArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = i;
	}
}

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

int main() {
	int** matrix;
	int n, m, min, spread, x = 0;

	seedInit();

	printf("-- Create a n-by-m matrix with random values, sorted increasingly --\n");
	printf("n = ");
	n = getInt();
	printf("m = ");
	m = getInt();

	// Creating matrix
	matrix = create2DMatrix(n, m);
	if (matrix == NULL) {
		return -1;
	}

	// Setting every value to 0
	zeroCustom2DMatrix(matrix, n, m);

	printf("Start value for 0/0: ");
	min = getInt();

	printf("How big should the max spread for the next random number be?\n> ");
	spread = getInt();

	matrix[0][0] = min;

	// Create random matrix with rising values in rows/columns
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			// First value is already entered			
			if (i == 0 && j == 0) {
				j++;
			}

			// Compare value to the left
			else if (i == 0 && j != 0) {
				min = matrix[i][j - 1];
			}

			// Compare value above
			else if (i != 0 && j == 0) {
				min = matrix[i - 1][j];
			}

			// Take highest value from left or above and set as min
			else {
				min = higherValue(matrix[i][j - 1], matrix[i - 1][j]);
			}

			matrix[i][j] = getRandomValue(min, min + spread);

		}
	}

	printCustom2DMatrix(matrix, n, m);

	return 0;
}

/*	
// Like this you will get a random matrix too, but it only compares the previous index
for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
		
		if (i == 0 && j == 0) {
			j++;
		}

		// Create a random value between min and min + 10, make it new min
		matrix[i][j] = getRandomValue(min, min + 10);
		min = matrix[i][j];
	}
}
*/