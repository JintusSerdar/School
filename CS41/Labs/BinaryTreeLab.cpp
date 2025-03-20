#include <iostream>
using namespace std;

class BinaryTree {
private:
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];
    int count;

public:
    BinaryTree() : count(0) {}

    void add(int value) {
        if (count < MAX_SIZE) {
            data[count] = value;
            count++;
        } else {
            cout << "Tree is full. Cannot add more elements." << endl;
        }
    }

    void preorder(int index) {
        if (index < count) {
            cout << data[index] << " ";
            preorder(2 * index + 1);
            preorder(2 * index + 2);
        }
    }

    void print() {
        cout << "Preorder traversal: ";
        preorder(0);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    tree.add(1);
    tree.add(2);
    tree.add(3);
    tree.add(4);
    tree.add(5);

    tree.print();

    return 0;
}