#include <iostream>
using namespace std;

int main() {
	int decimal;
	cout << "-- Convert Integer to Binary --\n";
	cout << "Integer value: ";
	cin >> decimal;
	int potenz = 0;

	// Find highest power
	int temp = decimal;
	while (temp != 0) {
		potenz++;
		temp = temp >> 1;
	}
	//cout << "Highest power: " << potenz << endl;

	cout << "Binary: ";
	while (potenz != 0) {
		// Shift MSB to LSB position, &compare against 1
		cout << ((decimal >> (potenz - 1)) & 1);
		potenz--; 
	}
	cout << endl;

}