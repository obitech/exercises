#include <iostream>
using namespace std;

int main() {
    int input;
    cout << "Bist Du krank? 1 = ja, 2 = nein\n> ";
    cin >> input;
    
    if (input == 1)
        cout << "Gute Besserung!\n";
    else if (input == 2)
        cout << "Super!\n";
    else 
        cout << "Falsche Eingabe.\n";
    
    return 0;
}    
