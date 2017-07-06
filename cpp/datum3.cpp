#include <iostream>
#include <string>
using namespace std;

int main () {
    int tag, jahr, monat_raw, monat, input;
    string monat_wort;
    
    cout << "-- Zahl ins Datumsformat --\n";
    cout << "Bitte Zahl im Format TTMMJJJJ eingeben: ";
    cin >> input;

    // 20102004
    // Jahr = 2004
    jahr = input % 10000;

    if (jahr < 0) {
        cout << "Ungültiges Datum.\n";
        return 0;
    }
    
    //monat= 10
    monat = ((input % 1000000) - jahr) / 10000;
    if ((monat > 0) && (monat < 13)) {
        switch(monat) {
            case 1 :
                monat_wort = "Januar";
                break;
            case 2 :
                monat_wort = "Februar";
                break;
            case 3 :
                monat_wort = "März";
                break;
            case 4 : 
                monat_wort = "April";
                break;
            case 5 : 
                monat_wort = "Mai";
                break;
            case 6 :
                monat_wort = "Juni";
                break;
            case 7 :
                monat_wort = "Juli";
                break;
            case 8 :
                monat_wort = "August";
                break;
            case 9 :
                monat_wort = "September";
                break;
            case 10 :
                monat_wort = "Oktober";
                break;
            case 11 : 
                monat_wort = "November";
                break;
            case 12 :
                monat_wort = "Dezember";
                break;
            default :
                cout << "Ungültiges Datum.\n";
                return 0;
        }
    }
    else {
        cout << "Ungültiges Datum.\n";
        return 0;
    }
    
    //tag = 20102004 - 102004 / 100000
    tag = input / 1000000;

    if ((tag <= 0) || (tag >= 32)) {
        cout << "Ungültiges Datum.\n";
        return 0;
    }
    
    cout << tag << ". " << monat_wort << " " << jahr << endl;
}    