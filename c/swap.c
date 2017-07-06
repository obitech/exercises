#include <stdio.h>

void swap_p(int *pa, int *pb);
void swap_n(int, int);

int main() {
	int x = 5;
	int y = 10;

	printf("-- No Pointers: --\n");
	printf("Pre-Swap: x = %d, y = %d\n", x, y);
	swap_n(x, y);
	printf("Post-Swap: x = %d, y = %d\n", x, y );

	printf("-- With Pointers: --\n");
	printf("Pre-Swap: x = %d, y = %d\n", x, y);
	swap_p(&x, &y);
	printf("Post-Swap: x = %d, y = %d\n", x, y );
}

void swap_n(int a, int b) {
	a = b;
	b = a;
}

void swap_p(int *pa, int *pb) {
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
