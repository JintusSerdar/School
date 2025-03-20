#include <iostream>
using namespace std;

// Node struct
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Stack class
class Stack {
private:
    Node* top;
    int count;

public:
    Stack() : top(nullptr), count(0) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        count++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty" << endl;
            return -1; // Or throw an exception
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
        return value;
    }

    bool isEmpty() {
        return count == 0;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Main function to exercise the stack
int main() {
    Stack stack;

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;

    stack.push(40);

    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    // Try to pop from an empty stack
    stack.pop();

    return 0;
}