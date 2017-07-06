// Berechnung von Weg und Geschwindigkeit nach t-Sekunden freier Fall

#include <iostream>
using namespace std;

// s = Weg, v = Geschwindigkeit, t = Zeit, g = Ortsfaktor
float s(int), v(int);
float g = 9.80665;

int main() {
	int t;
	cout << "-- Berechnung des freien Falls --\n";
	cout << "Bitte Zeit in Sekunden eigeben: ";
	cin >> t;

	cout << "Zurückgelegter Weg nach " << t << " Sekunden: " << s(t) << " m\n";
	cout << "Geschwindigkeit nach " << t << " Sekunden: " << v(t) << " m/s (" << v(t) * 3.6 << " km/h)\n";
}


float s(int t){
	return (g / 2) * (t * t);
}

float v(int t) {
	return g * t;
}