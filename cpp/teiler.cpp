#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "-- Prüfen ob a ein Teiler von b ist --\na = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    
    if (a == 0)
        cout << "Division durch 0 ist nicht möglich!\n";
    else if (b % a == 0)
        cout << "a ist ein Teiler von b\n";
    else 
        cout << "a ist kein Teiler von b\n";
    
    return 0;
}    

