#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class SortedLinkedList {
private:
    Node* head;

public:
    SortedLinkedList() : head(nullptr) {}

    // Insert a new value into the sorted list
    void insert(int value) {
        Node* newNode = new Node(value);

        // If the list is empty or the new value is smaller than the head
        if (!head || value < head->data) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Find the correct position to insert the new node
        Node* current = head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }

        // Insert the new node
        newNode->next = current->next;
        current->next = newNode;
    }

    // Print the entire list
    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free allocated memory
    ~SortedLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SortedLinkedList list;
    int input;

    // Main loop for user input
    while (true) {
        cout << "Enter a number (-1 to stop): ";
        cin >> input;

        if (input == -1) {
            break;
        }

        // Insert the number and print the current state of the list
        list.insert(input);
        cout << "Current list: ";
        list.printList();
    }

    // Print the final sorted list
    cout << "Final sorted list: ";
    list.printList();

    return 0;
} 