#include <iostream>
using namespace std;

int main() {
    int i, n, max = 0, sum = 0, input;
    float mid;
    
    cout << "-- Mittelwert/Maximum von Messwerten --\n";
    cout << "Anzahl an Messwerten:  ";
    cin >> n;
    
    for (i = 0; i < n; i++) {
        cout << "Messwert " << (i + 1) << " = ";
        cin >> input;
        
        sum += input;
        
        if (input >= max)
            max = input;
    }
    mid = (float)sum / (float)n;

    cout << "Durchschnitt = " << mid << ", Maximaler Wert = " << max << endl;
    return 0;
}
