#include <iostream>
using namespace std;

int main() {
	int tag, monat, jahr;
	int tdj = 0;

	cout << "-- Ermitteln des Tages in einem Jahr --\n";
	cout << "Tag = ";
	cin >> tag;
	cout << "Monat = ";
	cin >> monat;
	cout << "Jahr = ";
	cin >> jahr;

	// 30.02. existiert nicht.
	if ((monat == 2) && (tag > 29)) {
		cout << "Ungültiges Datum.\n";
		return 0;
	}	

	switch(monat) {
		// Wir addieren die Tage des vorhergehenden Monats
		case 12:
			// 30 Tage vom November
			tdj += 30;
		// Da kein break wird automatisch der nächste Fall abgearbeitet	
		case 11:
			tdj += 31;
		case 10:
			tdj += 30;
		case 9:
			tdj += 31;
		case 8:
			tdj += 30;
		case 7:
			tdj += 31;
		case 6:
			tdj += 30;
		case 5:
			tdj += 31;
		case 4:
			tdj += 30;
		case 3:
			// Schaltjahrprüfung
			if (((jahr % 4 == 0) && (jahr % 100 != 0)) || (jahr % 400 == 0))
				tdj += 29;
			else
				tdj += 28;
		case 2:
			tdj += 31;
		case 1:
			tdj += tag;
			break;
		default:
			cout << "Ungültiges Datum.\n";		
	}

	if ((tag > 0) && (tag < 32) && (monat > 0) && (monat < 13) && (jahr > 0))
		cout << "Der " << tag << "." << monat << "." << jahr << " ist der " << tdj << ". Tag des Jahres.\n";
	else
		cout << "Ungültiges Datum.\n"; 

	return 0;
}