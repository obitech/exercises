#include <stdio.h>
#include <stdlib.h>

// Input integer
int getInt() {
	int z;
	scanf("%d", &z);
	return z;
}

// Enter a n-by-m matrix
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

// Allocate memory for n-by-m matrix
int **create_mat(int n, int m) {
	int **matrix = malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++) {
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
}

// Transpose mat into mat_t
void trans_mat(int **mat, int **mat_t, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat_t[i][j] = mat[j][i];
		}
	}
}

int main() {
	int n, m, **mat, **mat_t;
	printf("-- Matrix Transposition --\n");
	printf("n = ");
	n = getInt();
	printf("m = ");
	m = getInt();

	printf("Startmatrix:\n");
	mat = get_mat(n, m);
	put_mat(mat, n, m);

	mat_t = create_mat(m, n);
	trans_mat(mat, mat_t, m, n);

	printf("Tansponierte Matrix:\n");
	put_mat(mat_t, m, n);

}