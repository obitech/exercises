// blutalkohol.cpp -- Berechnet Blutalkoholkonzentration annähernd

#include <iostream>
using namespace std;

int main(void)
{
	// Variablen:
	// bak = Massenanteil des Alkohols im Körper in Promille
	// a = Aufgenommene Masse des Alkohols in Gramm
	// m = Masse der Person in Kilogramm
	// v = Volumen des Getränkes in ml
	// e = Alkoholanteil in Prozent
	float bak, a, m, v, e;

	// Eingabe
	cout << "Körpermasse in kg: "; 
	cin >> m;
	cout << "Volumen des Getränkes in ml: "; 
	cin >> v;
	cout << "Alkoholanteil des Getränkes in Prozent: ";
	cin >> e;

	// Berechnung der aufgenommenen Alkoholmasse in Gramm
	a = v * (e / 100) * 0.8;

	// Berechnung der Blutalkoholkonzentration
	bak = a / (m * 0.62);

	// Ausgabe
	cout << "Aufgenommene Masse des Alkohols: "; cout << a; cout << " Gramm." << endl;
	cout << "Blutalkoholkonzentration: "; cout << (float)bak; cout << " Promille." << endl;

	return 0;
}