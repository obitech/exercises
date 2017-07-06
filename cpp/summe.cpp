#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "-- Ausgabe von Quadratzahlen --\n";
    cout << "n = ";
    cin >> n;
    
    for (int i = 1; i <= n * 2; i++) {
        if (i % 2 == 0) {
            sum += i;
            cout << "i = " << i << "sum = " << sum << endl;
        }
    }
    
    cout << "Die Summe der ersten " << n << " geraden Zahlen ist " << sum << endl;

}

/* 
n = 5
2, 4, 6, 8, 10 = 30
*/
