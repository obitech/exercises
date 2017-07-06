/* temperatur.cpp -- Umrechnung Fahrenheit/Celsius */
#include <iostream>
using namespace std;

int	main(void) 
{
	float c, f;
	int choice;

	cout << "Bitte Modus wählen:" << endl;
	cout << "1 - Fahrenheit -> Celsiuis" << endl;
	cout << "2 - Celsius -> Fahrenheit" <<endl;
	cout << "> "; cin >> choice;

	if (choice == 1)
	{
		cout << "Bitte Temperatur in Fahrenheit angeben: ";
		cin >> f;

		c = (5 * (f - 32)) / 9;
		cout << f; cout << " Fahrenheit = "; cout << c; cout << " Celsius." << endl;	
		return true;
	}	
	else if (choice == 2)
	{
		cout << "Bitte Temperatur in Celsius angeben: ";
		cin >> c;

		f = ((9 * c) + 160) / 5;
		cout << c; cout << " Celsius = "; cout << f; cout << " Fahrenheit." << endl;
		return false;
	}
	
	else 
	{
		cout << "Invalid command." << endl;

	}
}