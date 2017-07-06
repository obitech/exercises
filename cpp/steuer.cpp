// Berechnung der Mehrwertsteuer und des Bruttobetrags nach Eingabe
// von Netto und MwSt-Satz
#include <iostream>
using namespace std;

int main() {
	// Variablen abfragen
	int netto;
	int mwst_satz;

	cout << "Nettobetrag: ";
	cin >> netto;
	cout << "Mehrwertsteuersatz in %: ";
	cin >> mwst_satz;

	// Berechnen von Mehrwertsteuerbetrag und Bruttobetrag
	// Brutto / 100 = Netto / (100 - mwst_satz)
	float brutto = (100 * netto) / (100 - mwst_satz);
	float mwst = brutto - netto; 

	// Ausgabe
	cout << "-------" << endl;
	cout << "Mehrwertsteuer: ";
	cout << mwst << endl;
	cout << "Brutto: ";
	cout << brutto << endl;

	return 0; 
}
