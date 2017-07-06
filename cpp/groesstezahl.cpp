#include <iostream>
using namespace std;

int main() {
    int a, b, c, max;
    
    cout << "-- Ausgabe der größten von drei Zahlen --\na = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    
    if((a > b) && (a > c))
        max = a;
    else if((b > a) && (b > c))
        max = b;
    else
        max = c;
    
    cout << "Größte Zahl = " << max << endl;
}    
