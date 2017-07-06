#include <stdio.h>
#include <stdlib.h>

#define N 4

int nord(int matrix[N][N]) {
   int sum = 0;

   for (int i = 0; i < N/2; i++) {
      for (int j = i + 1; j < N - 1 - i; j++) {
         sum += matrix[i][j];
      }
   }

   return sum;
}

int west(int matrix[N][N]) {
   int sum = 0;

   for (int j = 0; j < N / 2; j++) {
      for (int i = 1 + j; i < N - 1 - j; i++) {
         sum += matrix[i][j];
      }
   }

   return sum;
}

int sud(int matrix[N][N]) {
   int sum = 0;
   for (int i = N - 1; i > N / 2; i--) {
      for (int j = N - i; j < i; j++) {
         sum += matrix[i][j];
      }
   }

   return sum;
}

int ost(int matrix[N][N]) {
   int sum = 0;
   for (int j = N - 1; j >  N / 2; j--) {
      for (int i = N - j; i <= j - 1; i++) {
         sum += matrix[i][j];
      }
   }

   return sum;
}

int main() {
   int matrix[N][N] = {
      {1, 4, 3, 4},
      {4, 5, 6, 4},
      {7, 8, 9, 4},
      {10, 11, 12, 4}
   };

   /* {1, 4, 3, 4, 7},
      {4, 5, 6, 4, 7},
      {7, 8, 9, 4, 7},
      {10, 11, 12, 4, 7},
      {12, 13, 14, 14, 15}*/

   printf("NORD = %d, WEST = %d, SUD = %d, OST = %d\n", nord(matrix), west(matrix), sud(matrix), ost(matrix));

}