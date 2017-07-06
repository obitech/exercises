#include <iostream>
using namespace std;

int main() {
	int input;
	cout << "-- Schaltjahrprüfung --\nBitte Jahr eingeben: ";
	cin >> input;

	if (input < 0) {
		cout << "Jahr muss größer als 0 sein.\n";
		return 0;
	}

	if (((input % 4 == 0) && (input % 100 != 0)) || (input % 400 == 0))
		cout << input << " ist ein Schaltjahr.\n";
	else
		cout << input << " ist kein Schaltjahr.\n";

	return 0;
}