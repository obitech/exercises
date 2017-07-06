/* AuP - Aufgabenblatt 4
Die Funktion unsigned int ggt(unsigned int a, unsigned int b) soll den größten 
gemeinsamen Teiler von a und b bestimmen. Verzichten Sie dabei auf die Rekursion.
*/

#include <stdio.h>

static unsigned int ggt(unsigned int, unsigned int);

int main() {
	unsigned int a = 45;
	unsigned int b = 30;

	printf("Der ggT von %d und %d ist %d\n", a, b, ggt(a, b));
}


unsigned int ggt(unsigned int a, unsigned int b) {
	unsigned int mod, c;

	// Euklidischer Weg, Rest wird zum divisor (nicht-rekursiv)
	mod = 1;
	while (mod != 0) {
		mod = a % b;
		a = b;
		b = mod;
	}

	return a;
}
