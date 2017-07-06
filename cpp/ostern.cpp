// ** Die Gaußsche Osterformel **
// Dies stellt die ergänzte Formel von Heiner Lichtenberg dar

#include <iostream>
#include <cmath> 
using namespace std;

int main() {
	int jahr, a, d, og, sz, oe, os, m, r, k, s;

	cout << "-- Gibt den Ostersonntag eines beliebigen Jahres aus --\n";
	cout << "Bitte Jahr eingeben: ";
	cin >> jahr;

	// 1. Die Säkularzahl
	k = jahr / 100;

	// 2. Die säkulare Mondschaltung
	m = 15 + (3 * k + 3) / 4 - (8 * k + 13) / 25;

	// 3. Die säkulare Sonnenschaltung
	s = 2 - (3 * k + 3) / 4;

	// 4. Der Mondparameter
	a =  jahr % 19;

	// 5. Keim für den ersten Vollmond im Frühling
	d = (19 * a + m) % 30;

	// 6. Die kalendarische Korrekturgröße
	r = (d + a / 11) / 29;

	// 7. Die Ostergrenze
	og = 21 + d - r;

	// 8. Der erste Sonntag im März
	sz = 7 - (jahr + jahr / 4 + s) % 7;

	// 9. Die Entfernung des Ostersonntags von der Ostergrenze
	oe = 7 - (og - sz) % 7;

	// 10. Das Datum des Ostersonntags als Märzdatum
	os = oe + og;

	if (os < 31)
		cout << "Der Ostersonntag des Jahres " << jahr << " ist der " << os << ". März\n";
	else {
		os -= 31;
		cout << "Der Ostersonntag des Jahres " << jahr << " ist der " << os << ". April\n";
	}

	return 0;
}