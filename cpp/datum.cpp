/*  Schreiben Sie ein Programm, das ein Datum als achtstellige Zahl der Form TTMMJJJJ als ganze Zahl einliest.
(Sie müssen nicht überprüfen, ob die Eingabe korrekt ist).
Das Programm soll das Datum in der Form TT.MM.JJJJ ausgeben.
*/

#include <iostream>
using namespace std;

int main () {
    int tag, jahr, monat_raw, monat, input;
    
    cout << "-- Zahl ins Datumsformat --\n";
    cout << "Bitte Zahl im Format TTMMJJJJ eingeben: ";
    cin >> input;

    // 20102004
    // Jahr = 2004
    jahr = input % 10000;
    
    //monat= 10
    monat= ((input % 1000000) - jahr) / 10000;
    
    
    //tag = 20102004 - 102004 / 100000
    tag = input / 1000000;
    
    cout << tag << "." << monat << "." << jahr << endl;
}    

/* Lösung mit String
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str = "";
    while (true) {
        cout << "Bitte Datum im Format TTMMJJJJ eingeben: ";
        getline(cin, str);

        if (str.length() == 8) {
            // Fügt . an Stellen 2 und 5 im String ein.
            str = str.insert(2, ".");
            str = str.insert(5, ".");

            cout << str << endl;
            break;
        }
        cout << "Ungültiges Format.\n";     
    }   
}
*/