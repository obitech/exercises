/* AuP WS 2016/17, Bonusaufgabe 2
-----------------------------------------------------------------
* Hauptidee:
** reverse ruft zweite Funktion increase() mit zwei Parametern
	old = input und new = 0 auf (Line 50)
** Rekursion mit increase(old / 10, (new * 10) + (old % 10))
** Rekursiver Ab- und Aufstieg geschehen hier "gleichzeitig"
	über die beiden Parameter old (Abstieg) und new (Aufstieg).
** Da im 1. Schritt new = 0 ist auch der (alte) Rest anfangs 0
** old wird kleiner, new wird größer
** Wenn old == 0 -> return new an reverse und dann main

* Limitations:
** Da mit ganzen Zahlen gearbeitet wird treten Probleme auf bei
	inputs die mit 0 anfangen oder aufhören
-> 001 oder kann nicht dargestellt werden
** Dies könnte mit string manipulation oder Arrays gelöst werden
----------------------------------------------------------------- 
* Schematischer Ablauf:
1) Nächste Stelle der neuen Zahl (new) = alte Zahl (old) % 10
		1. Schritt 123 % 10 						// = 3
		2. Schritt 12 % 10 						// = 2
		3. Schritt 1 % 10 						// = 1
Rekursiver Aufstieg:
	2) Neue Zahl = alter Rest * 10, + neuer Rest
		1. Schritt new = 0 * 10 + 3			// new = 3
		2. Schritt new = 3 * 10 + 2			// new = 32
		3. Schritt new = 32 * 10 + 1			// new = 321
Rekursiver Abstieg: 
	4) Zahl verkleinern (old = old / 10)
		1. Schritt old = 123 / 10 				// old = 12
		2. Schritt old = 12 / 10 				// old = 1
		3. Schritt old = 1 / 10 				// old = 0
5) Neuer Aufruf mit old & new
		1. Schritt increase(123,0)
		2. Schritt increase(12,3)
		3. Schritt increase(1,32)
		4. Schritt increase(0,321) --> return 321 to reverse, main
----------------------------------------------------------------- */

int printf(const char*, ...);
int atoi(const char*);

// Deklaration der Umkehrfunktion
int reverse(int);
// Deklaration des eigentlichen Algorithmus'
int increase(int, int);

int main(int carg, const char **varg) {
  // ein Parameter uebergeben?
  if (carg != 2) return -1;
  // gib den berechneten Wert aus
  printf("%d\n",reverse(atoi(varg[1])));
  // Rueckgabewert 0 bedeutet: alles okay
  return 0;
}

int reverse(int input) {
	return increase(input, 0);
}

int increase(int old, int new) {
	if (old == 0)
		return new;
	else
		return increase(old / 10, (new * 10) + (old % 10));
}


/* Weitere Möglichkeiten:
-----------------------------------------------------------------
** Rekursiv mit einer Funktion und extra Variable:

int sum = 0; 										// Globale Variable
int reverse(int input) {
	if (input == 0)
		return 0;
	else {
		sum = sum * 10 + (input % 10);
		reverse(input / 10);
		return sum;
	}	
}		
-----------------------------------------------------------------
** While loop:

int reverse(int input) {
	int sum = 0;
	while (input != 0) {
		sum = sum * 10 + (input % 10);
		input = input / 10;
	}
return sum;
}
----------------------------------------------------------------- */
