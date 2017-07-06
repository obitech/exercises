#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "-- Prüfen ob a oder b ein Teiler von 2 ist --\na = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    
    if ((a % 2 == 0) || (b % 2 == 0)) {
        cout << "Ja, ";
        
        if ((a % 2 == 0) && (b % 2 ==0))
            cout << "a und b sind Teiler von 2\n";
        else if (a % 2 == 0)
            cout << "a ist ein Teiler von 2\n";
        else
            cout << "b ist ein Teiler von 2\n";
    }
        
    else
        cout << "Nein, weder a noch b sind durch 2 teilbar\n";
    
    return 0;
}    

