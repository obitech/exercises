/* Fill a matrix in a different way, start by 1:
 * [1][2][5][...]
 * [4][3][6][...]
 * [9][8][7][...]
 * [...][...][...]
 */

#include <stdio.h>
#include <stdlib.h>

// Get integer input
int zahl() {
	int z;
	scanf("%d", &z);
	return z;
}

// Get value for matrix
int getMatrixValue(int i, int j) {
	printf("Enter value for %d/%d: ", i, j);
	return zahl();
}

// Fill array with 0
void zeroMatrix(int** array, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			array[i][j] = 0;
		}
	}
}

// Print array
void printMatrix(int** array, int size) {
	printf("\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d/%d: %d\t", i, j, array[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int n = 0;

	printf("-- Custom fill a  n-by-n Matrix --\n");

	printf("n = ");
	n = zahl();

	// Allocate memory for custom size 2d array
	int **matrix = malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		matrix[i] = malloc(n * sizeof(int));
	}

	// Check if memory allocation was successful
	if (matrix) {
		printf("\n%dx%d Matrix created:\n", n, n);
	}
	else {
		printf("Memory allocation error.\n");
		free(matrix);
		return -1;
	}

	// Zero array and print
	zeroMatrix(matrix, n);
	printMatrix(matrix, n);

	// Start value for 0/0
	printf("\nEnter value for 0/0: ");
	matrix[0][0] = zahl();

	for (int border = 1; border < n; border++) {
		for (int i = 0; i <= border; i++) {
			matrix[i][border] = getMatrixValue(i, border);
		}
		for (int i = border - 1; i >= 0; i--) {
			matrix[border][i] = getMatrixValue(border, i);
		}
	}

	printMatrix(matrix, n);

	return 0;
}

