#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// BST class
class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}

    // Add method
    void add(int value) {
        if (root == nullptr) {
            root = new Node(value);
            return;
        }

        Node* current = root;
        while (true) {
            if (value < current->data) {
                if (current->left == nullptr) {
                    current->left = new Node(value);
                    break;
                }
                current = current->left;
            } else if (value > current->data) {
                if (current->right == nullptr) {
                    current->right = new Node(value);
                    break;
                }
                current = current->right;
            } else {
                // Value already exists in the tree
                break;
            }
        }
    }

    // Print method 
    void print() {
        if (root == nullptr) {
            return;
        }

        Node* stack[100];  
        int top = -1;
        Node* current = root;

        while (current != nullptr || top >= 0) {
            while (current != nullptr) {
                stack[++top] = current;
                current = current->left;
            }

            current = stack[top--];
            cout << current->data << " ";
            current = current->right;
        }
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    bst.add(5);
    bst.add(3);
    bst.add(7);
    bst.add(1);
    bst.add(9);

    cout << "BST contents (inorder traversal): ";
    bst.print();

    return 0;
}