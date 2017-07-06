#include <iostream>
#include <cmath> 
using namespace std;

int main() {
	int i;

	// Zahlen die ein Teiler von 7 sind oder 7 enthalten werden nicht
	// berücksichtigt
	for (i = 1; i <= 100; i++) {
		if ((i % 7 != 0) && (i % 10 != 7) && (i / 10 != 7))
			cout << i << " ";
	}
	cout << endl;

	return 0;
}