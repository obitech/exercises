/**
 * Transform an integer into binary and fill an array with the numbers
 */
#include <stdio.h>
#include <stdlib.h>

// Input integer
int getInt() {
	int z;
	scanf("%d", &z);
	return z;
}

void printArray(int* array, int size) {

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

int main(int argc, char const *argv[]) {
	int number, *bin_array, potenz = 0;
	printf("-- Dec to Bin --\n");
	
	if (argc != 2) {
		printf("Invalid # of arguments.\n");
		return -1;
	}

	number = atoi(argv[1]);

   if (number <= 0) {
      printf("Please enter a positive integer.\n");
      return -2;
   }

	 // Find highest power
   int temp = number;
   while (temp != 0) {
      potenz++;
      temp = temp >> 1;
   }

   bin_array = malloc(potenz * sizeof(int));

   for (int i = 0; i < potenz; i++) {
   	bin_array[i] = (number >> (potenz - i - 1) & 1);
   }

   printf("Binary array: ");
   printArray(bin_array, potenz);

   return 0;
}