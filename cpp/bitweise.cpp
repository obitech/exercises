// Bitweise Verknüpfung von binären Werten

#include <iostream>
using namespace std;

int main() {
	int a, b;
	cout << "-- Bitweise Verknüpfung von Werten --\n";
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	cout << "\na AND b = " << (a & b) << endl;
	cout << "a OR b = " << (a | b) << endl;
	cout << "a XOR b = " << (a ^ b) << endl;
}