#include <iostream>
using namespace std;

int main() {
    int input, output;
    cout << "-- Absoluter Betrag einer Zahl--\n" << "Bitte Zahl eingeben: ";
    cin >> input;
    
    if(input < 0)
        output = input * - 1;
    else
        output = input;
    
    cout << "Betrag von " << input << " = " << output << endl;
    
    return 0;
}
