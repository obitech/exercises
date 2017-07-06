#include <iostream>
using namespace std;

int main() {
    long long long x;
    int i, fak = 1;
    cout << "-- Fakultaet einer Zahl --\n";
    cout << "x = ";
    cin >> x;
    
    for (i = 1; i <= x; i++) {
        fak *= i; 
    }    
    
    cout << "x! = " << fak << endl;
}    
