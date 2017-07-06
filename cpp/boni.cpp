#include <iostream>
using namespace std;

int main() {
    int gehalt, jahre, bonus;
    cout << "-- Berechnung des Bonus\' nach Länge der Betriebszugehörigkeit --\nGrundgehalt: ";
    cin >> gehalt;
    cout << "Arbeitsjahre: ";
    cin >> jahre;
    
    if ((jahre >= 5) && (jahre < 10)) {
        bonus = (3 * gehalt) / 100;
        cout << "Nach " << jahre << " Jahren gibt es einen monatlichen Bonus von " << bonus << endl;
    }
    
    else if ((jahre >= 10) && (jahre < 15)) {
        bonus = (8 * gehalt) / 100;
        cout << "Nach " << jahre << " Jahren gibt es einen monatlichen Bonus von " << bonus << endl;
    }
    
    else if (jahre >= 15) {
        bonus = (18 * gehalt) / 100;
        cout << "Nach " << jahre << " Jahren gibt es einen monatlichen Bonus von " << bonus << endl;
    }
    else
        cout << "Es wird noch kein Bonus ausgezahlt\n";
    
    return 0;
}    

