#include <iostream>

using namespace std;

int findSmallest(int* array, int low, int high) {
    int min = array[low];
    int pos = low;
    
    for (int i = low; i <= high; i++) {
        if (array[i] < min) {
            min = array[i];
            pos = i;
        }
    }
    
    return pos;
}

void printArray(int* array, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i == size - 1)
            cout << "]\n";
        else
            cout << ", ";
    }
}

int main() {
    int array[5] = {0, -1, 3, 8, -6};
    
    cout << "Array: ";
    printArray(array, 5);
    
    
}
