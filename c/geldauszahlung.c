#include <stdio.h>

typedef unsigned int uint;

void auszahlung_unbegrenzt(uint);
void auszahlung_begrenzt(int, int, int, int, int, int, int, int);

// Defining input
int zahl() {
	int z;
	scanf("%d", &z);
	return z;
}

int main() {
	int choice, input, s5, s10, s20, s50, s100, s200, s500;

STARTINPUT:
	printf("-- Auszahlung eines Geldbetrages --\n");
	printf("1 - Unbegrenzte Anzahl an Scheinen\n2 - Begrenzte Anzahl an Scheinen\n\n0 - Exit\n> ");
	choice = zahl();

	switch(choice) {
		case 0 :
			return 0;
		case 1 :
			printf("\nAuszahlung mit unbegrenzter Anzahl an Geldscheinen.\nBitte Betrag in Euro eingeben: ");
			input = zahl();
			auszahlung_unbegrenzt(input);

			return 0;
	 	case 2 :
	 		printf("Bitte Betrag in Euro eingeben: \n");
	 		input = zahl();
	 		
	 		printf("Bitte maximale Anzahl der Geldscheine eingeben:\n");
	 		printf("Max. 5 Euro Scheine: \n");
	 			s5 = zahl();
	 		printf("Max. 10 Euro Scheine: \n");
	 			s10 = zahl();
	 		printf("Max. 20 Euro Scheine: \n");
	 			s20 = zahl();	 			
	 		printf("Max. 50 Euro Scheine: \n");
	 			s50 = zahl();	 			
	 		printf("Max. 100 Euro Scheine: \n");
	 			s100 = zahl();
	 		printf("Max. 200 Euro Scheine: \n"); 		
	 			s200 = zahl();	 			
	 		printf("Max. 500 Euro Scheine: \n");
	 			s500 = zahl();

	 		auszahlung_begrenzt(input, s5, s10, s20, s50, s100, s200, s500);
	 		return 0;		

	 	default :
	 		printf("Invalid command\n");
	 		goto STARTINPUT;
	}
}


// Auszahlung eines Betrags mit unbegrenzter Anzahl an Scheinen
void auszahlung_unbegrenzt(unsigned int input) {
	int s5 = 0;
	int s10 = 0;
	int s20 = 0;
	int s50 = 0;
	int s100 = 0;
	int s200 = 0;
	int s500 = 0;
	int rest = 0;
	int orig = input;

	while(input >= 5) {
			if (input / 500) {
			s500 = input / 500;
			input = input % 500;
		}

		else if (input / 200) {
			s200 = input / 200;
			input = input % 200;
		}

		else if (input / 100) {
			s100 = input / 100;
			input = input % 100;
		}

		else if (input / 50) {
			s50 = input / 50;
			input = input % 50;
		}

		else if (input / 20) {
			s20 = input / 20;
			input = input % 20;
		}

		else if (input / 10) {
			s10 = input / 10;
			input = input % 10;
		}

		else if (input / 5) {
			s5 = input / 5;
			input = input % 5;
		}

		if (input < 5)
			rest = input;
	}

	printf("\n%d Euro wird in folgenden Scheinen ausgezahlt:\n", orig);
	if (s500 > 0)
		printf("%dx 500\n", s500);
	if (s200 > 0)
		printf("%dx 200\n", s200);
	if (s100 > 0)
		printf("%dx 100\n", s100);
	if (s50 > 0)
		printf("%dx 50\n", s50);		
	if (s20 > 0)
		printf("%dx 20\n", s20);
	if (s10 > 0)
		printf("%dx 10\n", s10);
	if (s5 > 0)
		printf("%dx 5\n", s5);
	if	(rest > 0)
		printf("%d Euro kann nicht mit Scheinen ausgezahlt werden.\n", rest);
}

// Auszahlung mit begrenzter Anzahl von Scheinen
// Input und maximale Anzahl an Scheinen wird übergeben
// max wird nach jedem Schritt verringert
void auszahlung_begrenzt(int input, int max5, int max10, int max20, int max50, int max100, int max200, int max500) {
	int s5 = 0;
	int s10 = 0;
	int s20 = 0;
	int s50 = 0;
	int s100 = 0;
	int s200 = 0;
	int s500 = 0;
	int rest = 0;
	int orig = input;

	while(input >= 5) {
		if ((input / 500) && (max500 >= 1)) {
			s500 = input / 500;
			max500 -= s500;
			input = input % 500;
		}

		else if ((input / 200) && (max200 >= 1)) {
			s200 = input / 200;
			max200 -= s200;
			input = input % 200;

		}

		else if ((input / 100) && (max100 >= 1)) {
			s100 = input / 100;
			max100 -= s100;
			input = input % 100;
		}

		else if ((input / 50) && (max50 >= 1)) {
			s50 = input / 50;
			max50 -= s50;
			input = input % 50;
		}

		else if ((input / 20) && (max20 >= 1)) {
			s20 = input / 20;
			max20 -= s20;
			input = input % 20;
		}

		else if ((input / 10) && (max10 >= 1)) {
			s10 = input / 10;
			max10 -= s10;
			input = input % 10;
		}

		else if ((input / 5) && (max5 >= 1)) {
			s5 = input / 5;
			max5 -= s5;
			input = input % 5;
		}
	
		else 
			break;
	}

	if (input < 5) {
		rest = input;
	}

	printf("\n%d Euro wird in folgenden Scheinen werden ausgezahlt:\n", orig - rest);
	if (s500 > 0)
		printf("%dx 500\n", s500);
	if (s200 > 0)
		printf("%dx 200\n", s200);
	if (s100 > 0)
		printf("%dx 100\n", s100);
	if (s50 > 0)
		printf("%dx 50\n", s50);		
	if (s20 > 0)
		printf("%dx 20\n", s20);
	if (s10 > 0)
		printf("%dx 10\n", s10);
	if (s5 > 0)
		printf("%dx 5\n", s5);
	if	(rest > 0)
		printf("%d Euro kann nicht mit Scheinen ausgezahlt werden.\n", rest);
	if (input > 0)
		printf("%d Euro können nicht ausgezahlt werden.\n", input);

	printf("\nFolgende Gelscheine sind noch übrig:\n%dx 500 Euro\n%dx 200 Euro\n%dx 100 Euro\n%dx 50 Euro\n%dx 20 Euro\n%dx 10 Euro\n%dx 5 Euro\n", max500, max200, max100, max50, max20, max10, max5);
}