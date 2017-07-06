#include <iostream>
#include <cmath> 
using namespace std;

int main() {
	int n, i, terminated = 0;
	double sum = 0.0, sum_last = 0.0, epsilon;

	cout << "-- Berechnung einer Harmonischen Reihe --\n";
	cout << "n = ";
	cin >> n;
	cout << "\nSummierung bricht ab, wenn Differenz zweier benachtbarten Glieder kleiner oder gleich Epsilon ist.\nEpsilon = ";
	cin >> epsilon;

	if (n <= 1) {
		cout << "Falscher Eingabewert";
		return 2;
	}

	for (i = 1; i <= n; i++) {
		sum += 1.0 / i;

		if (sum - sum_last <= epsilon) {
			cout << "Summierung terminiert, da H" << i << " - " << "H" << (i - 1) << " = " << (sum - sum_last) << " <= Epsilon (" << epsilon << ").\n";
			cout << "Partialsumme von H" << i << " = " << sum << endl;
			terminated = 1;
			break;
		}


		sum_last = sum;
	}

	if (!terminated)
		cout << "Die Partialsumme von H" << n << " = " << sum << endl;

	return 0;
}