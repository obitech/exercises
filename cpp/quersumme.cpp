#include <iostream>
using namespace std;

int main() {
    int x, zahl, sum = 0;
    cout << "-- Quersumme einer Zahl --\n";
    cout << "Zahl = ";
    cin >> x;
    zahl = x;

    while (x != 0) {
        sum += x % 10;
        x/= 10;
    }    
    
    cout << "Die Quersumme von " << zahl << " = " << sum << endl;
}

