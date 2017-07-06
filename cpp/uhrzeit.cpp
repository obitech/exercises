#include <iostream>
using namespace std;

int main() {
	int uhrzeit, min, std;
	cout << "-- Umwandlung des Uhrzeitformates --\nBitte Uhrzeit im Format hhmm eingeben: ";
	cin >> uhrzeit;
	min = uhrzeit % 100;
	std = uhrzeit / 100;
	std %= 12;

	switch(min) {
		case 0:
			cout << "um " << std << endl;
			break;
		case 15:
			cout << "viertel " << std + 1 << endl;	
			break;
		case 30:
			cout << "halb " << std + 1 << endl;
			break;
		case 45:	
			cout << "dreiviertel " << std + 1 << endl;
			break;
		default:
			cout << "Bitte Minuten im Wert von 0, 15, 30 oder 45 eingeben.\n";
	}

	return 0;
}