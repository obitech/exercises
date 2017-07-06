// Schreiben Sie ein C++ Programm, welches zwei Zahlen vom Benutzer einliest und diese dividiert. 
// Das Ergebnis soll korrekt auf Ganzzahlen gerundet werden. 
// (D.h. bis x.499999 abgerundet, ab x.5 aufgerundet werden.)

#include <iostream>
using namespace std;

int main() {
	float a, b, div;

	cout << "-- Division mit korrekter Rundung --\n";
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	div = a / b;

	// \t's for readability
	cout << a << "/" << b << "\t= " << "\t" << div << " (vor dem Ruden)\n";
	cout << "\t= " << "\t" << (int)(div + 0.5) << " (nach dem Runden)\n";
}