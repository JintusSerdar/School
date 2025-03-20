#include <iostream>
#include <string>

using namespace std;

// Node for doubly linked list
struct Node {
    string name;
    int weight;
    Node* nextName;
    Node* nextWeight;

    Node(const string& n, int w) : name(n), weight(w), nextName(nullptr), nextWeight(nullptr) {}
};

// DLL maintaining two sorted orders
class SortedDoublyLinkedList {
private:
    Node* headName;
    Node* headWeight;

public:
    SortedDoublyLinkedList() : headName(nullptr), headWeight(nullptr) {}

    // Insert a new node maintaining both sorted orders
    void insert(const string& name, int weight) {
        Node* newNode = new Node(name, weight);

        // Insert into name-sorted list
        if (!headName || name < headName->name) {
            newNode->nextName = headName;
            headName = newNode;
        } else {
            Node* current = headName;
            while (current->nextName && current->nextName->name < name) {
                current = current->nextName;
            }
            newNode->nextName = current->nextName;
            current->nextName = newNode;
        }

        // Insert into weight-sorted list
        if (!headWeight || weight < headWeight->weight) {
            newNode->nextWeight = headWeight;
            headWeight = newNode;
        } else {
            Node* current = headWeight;
            while (current->nextWeight && current->nextWeight->weight < weight) {
                current = current->nextWeight;
            }
            newNode->nextWeight = current->nextWeight;
            current->nextWeight = newNode;
        }
    }

    // Print list sorted by name
    void printByName() const {
        Node* current = headName;
        cout << "Names & weights sorted (ascending) by name: ";
        while (current) {
            cout << current->name << " - " << current->weight;
            if (current->nextName) cout << ", ";
            current = current->nextName;
        }
        cout << endl;
    }

    // Print list sorted by weight
    void printByWeight() const {
        Node* current = headWeight;
        cout << "Names & weights sorted (ascending) by weight: ";
        while (current) {
            cout << current->name << " - " << current->weight;
            if (current->nextWeight) cout << ", ";
            current = current->nextWeight;
        }
        cout << endl;
    }

    // Destructor
    ~SortedDoublyLinkedList() {
        Node* current = headName;
        while (current) {
            Node* temp = current;
            current = current->nextName;
            delete temp;
        }
    }
};

int main() {
    SortedDoublyLinkedList list;
    string name;
    int weight;
    const int TOTAL_PEOPLE = 15;

    for (int i = 0; i < TOTAL_PEOPLE; ++i) {
        cout << "Enter name #" << (i + 1) << ": ";
        getline(cin, name);
        cout << "Enter weight for " << name << ": ";
        cin >> weight;
        cin.ignore(); // To ignore the newline character after the weight input
        list.insert(name, weight);
    }

    list.printByName();
    list.printByWeight();

    return 0;
}