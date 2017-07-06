#include <iostream>
using namespace std;

int main() {
    int input, i, prim = 0;
    
    cout << "-- Prüfen ob Eingabe eine Primzahl ist --\n";
    cout << "Zahl = ";
    cin >> input;
    
    for (i = input - 1; i >= 2; i--) {
        if (input % i == 0) {
            prim = 0;
        }
        else 
            prim = 1;
    }    
    
    if (prim == 0) 
        cout << input << " ist keine Primzahl.\n";
    else
        cout << input << " ist eine Primzahl.\n";
    
    return 0;
}
