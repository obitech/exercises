#include "determinant.h"

// Get cofactor at position matrix[0][cur_row]
void cofactor(int **temp, int **matrix, int n, int cur_row) {
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (j == cur_row) {
            temp[i][j] = matrix[i + 1][j + 1];
         }
         else {
            if (cur_row == 0) {
               temp[i][j] = matrix[i + 1][j + 1];
            } 
            else {
               temp[i][j] = matrix[i + 1][j];
            }
         }
      }
   }
}

int determinant(int **matrix, int n) {
   int **temp, prod, sign;

   if (n == 1) {
      return matrix[0][0];
   }

   else {
      // Cofactor matrix
      temp = create_custom_2D_matrix(n - 1, n - 1);
      prod = 0;
      sign = 1;

      for (int i = 0; i < n; i++) {
         
         cofactor(temp, matrix, n - 1, i);

         prod += sign * matrix[0][i] * determinant(temp, n - 1);

         sign = -sign;
      }

      free(temp);
      
      return prod;
   }
}