// AuP - Implementing the Horner Method
#include <stdio.h>

static int zahl();
static int power(int,unsigned int);
static int horner_iterativ(unsigned int, int);
static int horner_recursive(unsigned int, int, int);
static int horner_recursive_2(unsigned int, int max, int, int);

int main(){
	int n, x, output, choice, a_start, max;

START:
	printf("-- Calculating a polynom with the Horner method --\n");
	printf("n = ");
		n = zahl();
	printf("x = ");
		x = zahl();

	printf("\nMethods::\n");
METHODCHOICE:		
	printf("1 - via iteration\n2 - via recursion, a is descending [a(n)...a(0)]\n3 - via recursion, a is ascending [a(0)...a(n)]\n\n0 - Exit\n99 - Re-enter values\n> ");
	choice = zahl();
	switch(choice) {
		case 0 :
			return 0;
		case 1 :
			printf("\n- Horner method, iterative:\n");
			printf("Result: %d\n", horner_iterativ(n, x));
			return 0;
		case 2 :
			printf("\n- Horner method, recursive [a(n)...a(0)]:\n");
			printf("a(%d) = ", n);
			a_start = zahl();
			printf("Result: %d\n", horner_recursive(n, x, a_start));
			return 0;
		case 3 :
			printf("\n- Horner method, recursive [a(0)...a(n))]:\n");
			max = n;
			printf("a(%d) = ", max - n);
			a_start = zahl();
			printf("Result: %d\n", horner_recursive_2(0, n, x, a_start));
			return 0;
		case 4 :
			goto START;
		default :
			printf("Invalid input.\n");
			goto METHODCHOICE;
		}	
}

// Defining input (zahl = number)
int zahl() {
	int z;
	scanf("%d", &z);
	return z;
}

//  Defining function to calculate a to the power of b
int power(int a, unsigned int b) {
	if (b == 0)
		return 1;
	else
		return a * power(a, b - 1);
}

// Defining function for iterative calculation
int horner_iterativ(unsigned int n, int x) {
	int output = 0;
	int n_max = n;

	for (int i = n_max; i >= 0; --i) {
		printf("a(%d) = ", i);
		output += zahl() * power(x, n);
		n = n - 1;
	}
	return output;
}

// Defining function for recursive calc. w/ descending a's 
int horner_recursive(unsigned int n, int x, int a){
	int a_tmp;

	if (n == 0)
		return a;
	else {
		printf("a(%d) = ", n - 1);
		a_tmp = zahl();
		return a * power(x, n) + horner_recursive(n - 1, x, a_tmp);
	}
}

// Defining function for recursive calc. w/ ascending a's
int horner_recursive_2(unsigned int n, int max, int x, int a) {
	int a_tmp;
	
	if (n == max)
		return a * power(x, n);
	else {
		printf("a(%d) = ", n + 1);
		a_tmp = zahl();
		return a * power(x, n) + horner_recursive_2(n + 1, max, x, a_tmp);
	}
} 