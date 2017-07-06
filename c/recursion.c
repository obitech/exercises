// AuP - Recursion practice
#include <stdio.h>

// Handling user input
int input() {
	int z;
	scanf("%d", &z);
	return z;
}

// 1 - Return the nth-Fibonacci number
static int fibo(int n) {
	if (n <= 0) 
		return 0;
	else if (n == 1)
		return 1;
	else 
		return fibo(n - 1) + fibo(n - 2);
}

// 2 - Multiplication of two integers
static int mult(int a, int b) {
	if (a == 1)
		return b;
	else if (b == 1) {
		return a;
	}
	else
		return mult(a, 1) * mult(1, b);
}

// 3 - Calculate a to the power of b
static int expo(int a, unsigned int b) {
	if (b == 0)
		return 1;
	else
		return a * expo(a, b - 1);
}


int main() {
	int choice, n, a , b;
	printf("-- Practicing recursive algorithms --\n");

CHOICES:
	printf("What do you want to solve?\n");
	printf("1 - Show the n-th Fibonacci number\n");
	printf("2 - Multiply two numbers\n");
	printf("3 - Exponentation\n");
	printf("\n0 - Exit\n");

	printf("> ");
	choice = input();
	switch(choice) {
		case 0 :
			return 0;
		case 1 :
			printf("Finding the n-th Fibonacci number. Please enter n: ");
			n = input();
			
			printf("%dth Fibonacci number = %d\n", n, fibo(n));
			return 0;

		case 2 :
			printf("Multiply a and b\n");
			printf("a = ");
			a = input();
			printf("b = ");
			b = input();

			printf("Result: %d\n", mult(a, b));
			return 0;

		case 3 :
			printf("Exponentation:\nBase a = ");
			a = input();
			printf("Exponent b = ");
			b = input();

			printf("%d-th power of %d = %d\n", b, a, expo(a, b));
			return 0;

		default :
			printf("Invalid input.\n");
			goto CHOICES;		
	}
}

