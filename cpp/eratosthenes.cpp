/* Printing all primes up to n using Eratosthenes' sieve algorithm */

#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

// Returns integer (typesafe)
int get_int() {
    while (true) {
        string input;
        int temp;

        getline(cin, input);
        stringstream inputStream(input);
        if (inputStream >> temp) {
            if (temp >= 0) {
                return temp;
            }
        }
        cout << "Invalid value, please try again: ";
    }   
}

// Returns an array with all primes up to n, pointer on size variable for returning array
int *sieve(int n, int* size) {

    int length = 0, c = 0;

    // Creates an array with numbers which will be checked against
    int * check = new int[n + 1];

    for (int i = 0; i <= n; i++) {
        check[i] = i;
    }

    // Start checking for primes, removing multiples of those which are not
    for (int i = 2; i <= sqrt(n); i++) {
        if (check[i] != 0) {
            // it's prime, remove all multiple
            for (int j = i * i; j <= n; j += i) {
                check[j] = 0;
            }
        }
    }

    // Getting size of returning array
    for (int i = 2; i <= n; i++) {
        if (check[i] != 0) {
            length++;
        }
    }

    // Creating returning array
    int * output = new int[length];
    for (int i = 2; i <= n; i++) {
        if (check[i] != 0) {
            output[c] = check[i];
            c++;
        }
    }

    delete []check;

    *size = length;
    return output;
}

void print_array(int* array, int size) {

    if (!array) {
        cout << "NULL\n";
    }

    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i != size - 1) {
            cout << ",";
        }
    }
    cout << "]\n";

    return;
}


int main() {
    int n, size;

    cout << "-- Printing all primes up to n --\n";
    cout << "n = ";
    n = get_int();

    int * prime_array = sieve(n, &size);
    print_array(prime_array, size);

    delete []prime_array;

    return 0;
}