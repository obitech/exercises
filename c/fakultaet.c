/* AuP - Aufgabenblatt 4
Die Funktion unsigned int fak(unsigned int n)
soll die Fakultät von n berechnen. */

#include <stdio.h>

int fak(int);

int main(void) {
	int n = 5;

	printf("%d! = %d\n", n, fak(n));

}

int fak(int x) {
	if (x <= 1) return 1;
	return x * fak(x - 1);
}
