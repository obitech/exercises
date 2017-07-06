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

// Allocate memory for n-x-m matrix
int **create_mat(int n, int m) {
	int **matrix = malloc(n * sizeof(int*));

	for (int i = 0; i < m; i++) {
		matrix[i] = malloc(m * sizeof(int));
	}

	return matrix;
}

// Print n-by-m matrix
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

// mat3 = mat1 + mat2
void add_mat(int **mat1, int **mat2, int **mat3, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat3[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
}

// mat3 = mat1 - mat2
void sub_mat(int **mat1, int **mat2, int **mat3, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat3[i][j] = mat1[i][j] - mat2[i][j];
		}
	}
}

int main() {
	int **mat1, **mat2, **mat3;
	int n, m;

	printf("-- Add/Sub of matrices --\n");
	printf("n = ");
	n = getInt();
	printf("m = ");
	m = getInt();

	printf("Matrix 1:\n");
	mat1 = get_mat(n, m);
	put_mat(mat1, n, m);

	printf("Matrix 2:\n");
	mat2 = get_mat(n, m);
	put_mat(mat2, n, m);

	printf("Add(mat1, mat2): \n");
	mat3 = create_mat(n, m);
	add_mat(mat1, mat2, mat3, n, m);
	put_mat(mat3, n, m);

	printf("Sub(mat1, mat2):\n");
	sub_mat(mat1, mat2, mat3, n, m);
	put_mat(mat3, n, m);

}