#include <iostream>
using namespace std;

class HashTable {
private:
    static const int SIZE = 27;
    int table[SIZE] = {0};        
    bool isEmpty[SIZE] = {true};  

public:
    // Constructor 
    HashTable() { } 

    // Hash function
    int Hash(int value) {
        return value % SIZE;
    }

    // Add function with linear probing
    void Add(int value) {
        int index = Hash(value);
        
        // If spot is taken, do linear probing
        while (!isEmpty[index]) {
            index = (index + 1) % SIZE;
        }
        
        table[index] = value;
        isEmpty[index] = false;
    }

    // Lookup function
    int Lookup(int value) {
        int index = Hash(value);
        int startIndex = index;
        
        do {
            if (isEmpty[index]) {
                return -1;  // Empty spot found before value, so value isn't in table
            }
            if (table[index] == value) {
                return index;  // Found the value
            }
            index = (index + 1) % SIZE;
        } while (index != startIndex);  // Stop if we've checked entire table
        
        return -1;  // Value not found
    }
};

int main() {
    HashTable ht;
    int choice, value;
    int result;  

    while (true) {
        cout << "\n1. Add number\n";
        cout << "2. Look up number\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number to add: ";
                cin >> value;
                ht.Add(value);
                cout << "Value " << value << " was added to the hash table\n";
                break;
                
            case 2:
                cout << "Enter number to look up: ";
                cin >> value;
                result = ht.Lookup(value); 
                if (result != -1)
                    cout << "Value " << value << " was found at index " << result << endl;
                else
                    cout << "Value " << value << " was not found in the hash table\n";
                break;
                
            case 3:
                return 0;
                
            default:
                cout << "Invalid choice!\n";
        }
    }
    
    return 0;
}
