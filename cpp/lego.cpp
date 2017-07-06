#include <iostream>
#include <cmath> 
using namespace std;

int main() {
	int h, sum = 0, i;
	cout << "-- Bau einer Legotreppe --\n";
	cout << "Höhe der Treppe = ";
	cin >> h;

	if (h < 1) {
		cout << "Treppe muss mindestens Höhe 1 haben!\n";
		return 2;
	}

	for (i = h; i >= 1; i--) {
		sum += i;
	}

	cout << "Für eine Treppe der Höhe " << h << " werden " << sum << " Legosteine benötigt.\n";

	return 0;
}


/*
sum = 4
sum = 4 + 3 	= 7
sum = 7 + 2		= 9
sum = 7 + 1 	= 10
*/