#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Create a dynamic array
    int* numbers = new int[size];
    int count = 0;
    int input;

    // Input numbers
    while (count < size) {
        cout << "Enter a number (-1 to stop): ";
        cin >> input;

        if (input == -1) {
            break;
        }

        numbers[count] = input;
        count++;
    }

    // Print the list
    cout << "Numbers entered: ";
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Free the allocated memory
    delete[] numbers;

    return 0;
}