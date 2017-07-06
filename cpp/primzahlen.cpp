#include <iostream>
#include <cmath>

using namespace std;

int primTest(int n) {
    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

void printPrime(int limit) {
    for (int i = 1; i <= limit; i++) {
        if (primTest(i)) {
            cout << i << ", ";
        }
    }
    cout << endl;
}

int main() {
    int n = 0;
    
    cout << "n = ";
    cin >> n;
    
    printPrime(n);
}
