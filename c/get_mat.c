#include <stdio.h>
#include <stdlib.h>

// Input integer
int getInt() {
	int z;
	scanf("%d", &z);
	return z;
}

// Enter a n-x-m matrix
int **get_mat(int n, int m) {
	int **matrix = malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++) {
		matrix[i] = malloc(m * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("(%d/%d): ", i, j);
			matrix[i][j] = getInt();
		}
	}

	return matrix;
}

// Print a n-by-m matrix
void put_mat(int **matrix, int n, int m) {
	printf("%d by %d Matrix:\n", n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//  Recursively print a n-by-m matrix
void put_mat_rek(int **matrix, int n, int m, int i, int j) {
	if ((i == n - 1) && (j == m - 1)) {
		printf("%d\n", matrix[i][j]);
		return;
	}

	else {
		printf("%d\t", matrix[i][j]);

		if (j == m - 1) {
			printf("\n");
			put_mat_rek(matrix, n, m, i + 1, m - m);
		}

		put_mat_rek(matrix, n, m, i, j + 1);


	}

}

int main() {
	int n, m;
	int **matrix;

	printf("-- Get/Put n-x-m Matrix --\n");
	printf("n = ");
	n = getInt();

	printf("m = ");
	m = getInt();

	matrix = get_mat(n, m);
	put_mat(matrix, n, m);

}