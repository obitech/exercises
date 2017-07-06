#include <stdio.h>

static int fn1(unsigned int);
static int power(int, unsigned int);
static unsigned int digits1(unsigned int);
static unsigned int bug(unsigned int);
static unsigned int sumbug(unsigned int);
static unsigned int sum(unsigned int);
static int polynom(unsigned int, int);
static int polynom2(unsigned int, int);

int main() {
	int n = 4;
	int x = 2;
	printf("fn1(%d) = %d\n", n, fn1(n));
	printf("n hat %d Stellen.\n", digits1(n));
	printf("Bounty für den %d. Bug = %d Cent\n", n, sum(n));
	printf("Bounty für %d Bugs = %d Cent\n", n, sumbug(n));
	printf("Basis = %d, Exponent = %d, Ergebnis = %d\n", x, n, power(x, n));
	printf("Polynom von x = %d und n = %d = %d\n", x, n, polynom(n, x));
	printf("Polynom2 von x = %d und n = %d = %d\n", x, n, polynom2(n, x));	
}
// Berechnet ein Polynom der Form: x^n + x^n-1 + ... + x^2 + x + 1
// n = Exponent, x = Basis
int polynom(unsigned int n, int x) {
	if (n == 0) 
		return 1;
	else 
		return power(x, n) + polynom(n - 1, x);
}

// Berechnet ein Polynom der Form -1^n * x^n + (-1)^n-1 * x^n-1 + ... + x^2 - x + 1
// n = Exponent, x = Basis
int polynom2(unsigned int n, int x) {
	if (n == 0) 
		return 1;
	else 
		return (power(-1, n)* power(x, n)) + polynom2(n - 1, x);
}

//Donald Knuth zahlte der ersten Person, die einen Bug in seinem Textsatzsystem TEX fand, 
//1¢ als Belohnung aus. Für jeden weiteren Bug versprach er das 
//Doppelte der Belohnung des letzten Bugs zu zahlen.
//sum(n) gibt die Belohnung für den n-ten Bug aus. 
unsigned int sum(unsigned int n) {
	unsigned int i, bounty, tmp;
	tmp = 1;

	for (i = 1; i < n; i++) {
		bounty = 2 * tmp;
		tmp = bounty;
	}
	return bounty;
}

//Gibt die Belohnung für alle Bugs aus
unsigned int sumbug(unsigned int n) {
	unsigned int tmp = 1;

	if (n == 1)
		return 1;
	else {
		tmp += 2 * sumbug(n-1);
		return tmp;
	}
}

// Berechnung von Summe aus i = 1 bis n über (-1) ^ i * i
int fn1(unsigned int n) {
	int output = 0;
	for (int i = 1; i <= n; i++) {
		output += power(-1, i) * i;
	}
	return output;
}

int power(int a, unsigned int b) {
	if (b == 0)
		return 1;
	else
		return a * power(a, b - 1);
}

// Anzahl der Ziffern von n
unsigned int digits1(unsigned int n) {
	unsigned int tmp = 1;
	unsigned int check = 1;
	unsigned int count = 0;

	while (tmp != 0) {
		tmp = n / check;
		check *= 10;
		count += 1;
	}
	return count - 1;
}