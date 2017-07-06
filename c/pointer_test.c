#include <stdio.h>

int main() {
	float a = 42.0;		// a ist Integer mit Wert 42
	float *b;			// *a ist ein Pointer der auf Integer zeigt
	void *c;			// *b ist ein Pointer auf eine Adresse zeigt

	b = &a;
	c = &a;

	printf("Die Variable a hat den Wert %f und die Adresse %p\n", a, &a);
	printf("Pointer *b zeigt auf die Adresse von a. b = %p\n", b);
	printf("Void-Pointer c zeigt auf a. c = %p\n", c);
	printf("Die Adressen der Pointer: b = %p, c = %p\n", &b, &c);
	printf("Dereferenzierung mit *, *b = : %f\n", *b);
	printf("----------------\n");

	int zahl = 10;
	int *pointer1, **pointer2, *pointer3;
	pointer1 = &zahl;
	pointer2 = &pointer1;

	printf("Zahl = %d, Adresse(Zahl) = %p\n\n", zahl, &zahl);
	printf("Pointer 1 zeigt auf Zahl.\n\tpointer1 = %p\n\tAdresse(pointer1) = %p\n\n", pointer1, &pointer1);
	printf("Pointer 2 zeigt auf Pointer 1.\n\tpointer 2 = %p\n\t*pointer2 = %p\n\t**pointer 2 = %d\n\n", pointer2, *pointer2, **pointer2);

	**pointer2 = 25;
	printf("**pointer2 = %d, Zahl = %d\n", **pointer2, zahl);
	printf("pointer 1 + 1 --> Adresse = %p, Wert = %d\n", pointer1 + 1, *(pointer1 + 1));

}