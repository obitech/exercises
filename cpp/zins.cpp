// Berechnung des Zinseszins

#include <iostream>
#include <cmath> 
using namespace std;

int main() {
	int start, betrag, ziel, jahre = 0;
	double zins;
	
	cout << "Startbetrag in Euro = ";
	cin >> start;
	betrag = start;
	cout << "Zielbetrag in Euro = ";
	cin >> ziel;
	cout << "Zinssatz in % = ";
	cin >> zins;

	if ((ziel <= start) || (zins <= 0)) {
		cout << "Falsche Eingabe.\n";
		return 1;
	}

	while (betrag < ziel) {
		jahre += 1;
		betrag = ((zins / 100) * betrag) + betrag;
	}

	cout << "Bei einem Startbetrag von " << start << " Euro und Zinssatz von " << zins << "\% ist der Zielbetrag von " << ziel << " Euro nach " << jahre << " Jahren erreicht.\n";

	return 0;
}