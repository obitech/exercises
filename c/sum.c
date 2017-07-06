// AuP - Aufgabenblatt 4
#include <stdio.h>

static unsigned int sum(unsigned int);

int main () {
	unsigned int n = 8;
	printf("Summe der ersten %d natuerlichen Zahlen = %d\n", n, sum(n));
}

unsigned int sum(unsigned int x) {

	if (x == 1) return 1;
	else return x = x + sum(x - 1);
}