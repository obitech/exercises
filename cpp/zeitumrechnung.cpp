/* zeitumrechnung.cpp -- Umrechnung von Sekunden in Timer format: h:m:s */
#include <iostream>
#include <string>
using namespace std;

int hours(int), minutes(int), seconds(int);

int main(void)
{
	int input;
	string choice;
	cout << "-- Umrechnung von Sekunden in Timer-format --\n";

	while (true) {
		cout << "Bitte Sekunden eingeben: ";
		cin >> input;
		
		if ((input >= 0) && !cin.fail()) {
			cout << hours(input) << ":" << minutes(input) << ":" << seconds(input) << endl;
			
			cout << "Again? y/n ";
			cin >> choice;

			// Unsauber, need better way to jump back up!!
			if (choice == "n") return 0;
			else main();
		}
		else 
			cout << "Wrong entry.\n";

	} 

}

int hours(int input) {
	return input / 3600;
}

int minutes(int input) {
	return (input % 3600) / 60;
}

int seconds(int input) {
	return input % 60;
}