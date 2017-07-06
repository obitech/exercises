// Primfaktorzerlegung mit Schleifen, ohne Array
#include <iostream>
#include <cmath> 
using namespace std;

// Check if prime
int prim(int zahl) {
	if (zahl == 1 || zahl == 2)
		return 1;
    for (int i = zahl - 1; i >= 2; i--) {
        if (zahl % i == 0) {
            prim = 0;
            break;
        }
        else 
            prim = 1;
    } 

    return prim;
}

int main() {
	int i, zahl, check = 1;
	cout << "-- Primfaktorzerlegung --\n";
	cout << "Zahl = ";
	cin >> zahl;

	// Terminating loop when all prime factors are found
	while (check != zahl) {
		for (i = 2; i < zahl; i++) {
			if ((zahl % i == 0) && (prim(i) == 1)) {
				cout << "Primfaktor: " << i << endl;
				check *= i;
			}
		}
	}  

	return 0;
}