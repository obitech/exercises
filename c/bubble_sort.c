#include <stdio.h>
#include <stdlib.h>

void print_array(int* array, int size) {

   if (!array) {
      printf("NULL");
   }

   printf("[");
   for (int i = 0; i < size; i++) {
      printf("%d", array[i]);

      if (i != size - 1) {
         printf(",");
      }
   }
   printf("]\n");
}

void bubble_sort(int *arr, int size) {
   int swap = 1, min;

   while (swap) {
      swap = 0;

      for (int i = 0; i <= size - 2; i++) {
         min = arr[i];
         if (arr[i + 1] < min) {
            min = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = min;
            swap = 1;
         }
      }
   }
}

int main(int argc, char const *argv[])
{
   if (argc <= 2) {
      printf("Invalid # of arguments.\n");
      return -1;
   }

   int size = argc - 1;
   int *array = malloc((size) * sizeof(int));

   for (int i = 0; i < size; i++) {
      array[i] = atoi(argv[i + 1]);
   }

   printf("Input array: ");
   print_array(array, size);

   bubble_sort(array, size);
   printf("Sorted array: ");
   print_array(array, size);


   return 0;
}