#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "-- Sortieren von 3 Zahlen mit if's --\na = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    
    if ((a >= b) && (b >= c))
        cout << c << ", " << b << ", " << a << endl;
    else if ((a >= c) && (c >= b))
        cout << b << ", " << c << ", " << a << endl;
    else if ((b >= a) && (a >= c))
        cout << c << ", " << a << ", " << b << endl;
    else if ((b >= c) && (c >= a))
        cout << a << ", " << c << ", " << b << endl;
    else if ((c >= a) && (a >= b))
        cout << b << ", " << a << ", " << c << endl;
    else
        cout << a << ", " << b << ", " << c << endl;
    
    return 0;
}    
