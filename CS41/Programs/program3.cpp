#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int weight;
    Node* left;
    Node* right;
    Node(string n, int w) : name(n), weight(w), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    // Helper methods
    Node* insertRecursive(Node* node, string name, int weight) {
        // If we reach an empty spot, create a new node
        if (!node) return new Node(name, weight);
        // Decide whether to go left or right based on the name
        if (name < node->name) node->left = insertRecursive(node->left, name, weight);
        else if (name > node->name) node->right = insertRecursive(node->right, name, weight);
        return node;
    }

    void traverseRecursive(Node* node, int order) {
        if (!node) return;
        // Print before recursion for preorder
        if (order == 0) cout << node->name << " ";
        traverseRecursive(node->left, order);
        // Print between left and right for inorder
        if (order == 1) cout << node->name << " ";
        traverseRecursive(node->right, order);
        // Print after recursion for postorder
        if (order == 2) cout << node->name << " ";
    }

    int getHeightRecursive(Node* node) {
        if (!node) return 0;
        // Height is the max of left and right subtree heights, plus 1 for this node
        return 1 + max(getHeightRecursive(node->left), getHeightRecursive(node->right));
    }

    int countLeavesRecursive(Node* node) {
        if (!node) return 0;
        // A leaf has no children
        if (!node->left && !node->right) return 1;
        // If not a leaf, sum leaves in left and right subtrees
        return countLeavesRecursive(node->left) + countLeavesRecursive(node->right);
    }

    Node* searchRecursive(Node* node, string name) {
        if (!node || node->name == name) return node;
        return (name < node->name) ? searchRecursive(node->left, name) : searchRecursive(node->right, name);
    }

    int findLowestWeightRecursive(Node* node) {
        if (!node) return INT_MAX;
        return min(node->weight, min(findLowestWeightRecursive(node->left), findLowestWeightRecursive(node->right)));
    }

    string findFirstAlphabeticalRecursive(Node* node) {
        return node->left ? findFirstAlphabeticalRecursive(node->left) : node->name;
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Insert a new name and weight into the tree
    void insert(string name, int weight) { root = insertRecursive(root, name, weight); }

    // Print the tree in preorder
    void preorderTraversal() { cout << "Preorder: "; traverseRecursive(root, 0); cout << endl; }

    // Print the tree in inorder
    void inorderTraversal() { cout << "Inorder: "; traverseRecursive(root, 1); cout << endl; }

    // Print the tree in postorder
    void postorderTraversal() { cout << "Postorder: "; traverseRecursive(root, 2); cout << endl; }

    // Get the height
    int getHeight() { return getHeightRecursive(root); }

    // Count the number of leaf nodes
    int countLeaves() { return countLeavesRecursive(root); }

    // Search 
    void search(string name) {
        Node* result = searchRecursive(root, name);
        if (result) cout << "Found: " << result->name << ", Weight: " << result->weight << endl;
        else cout << "No match for " << name << endl;
    }

    // Find the lowest weight
    int findLowestWeight() { return root ? findLowestWeightRecursive(root) : throw runtime_error("Empty tree"); }

    // Find the first name alphabetically
    string findFirstAlphabetical() { return root ? findFirstAlphabeticalRecursive(root) : throw runtime_error("Empty tree"); }
};

int main() {
    BinarySearchTree bst;
    // Input loop for 15 records
    for (int i = 0; i < 15; i++) {
        string name; int weight;
        cout << "Name " << (i + 1) << ": "; cin >> name;
        cout << "Weight: "; cin >> weight;
        bst.insert(name, weight);
    }

    // Perform tree traversals
    bst.preorderTraversal();
    bst.inorderTraversal();
    bst.postorderTraversal();
    cout << "Tree height: " << bst.getHeight() << endl;
    cout << "Leaf count: " << bst.countLeaves() << endl;
    
    // Search for a name
    string searchName;
    cout << "Enter name to search: "; cin >> searchName;
    bst.search(searchName);

    // Find lowest weight and first alphabetical name
    cout << "Lowest weight: " << bst.findLowestWeight() << endl;
    cout << "First alphabetically: " << bst.findFirstAlphabetical() << endl;
    return 0;
}

/* Sample Output

Name 1: Mike
Weight: 220
Name 2: Brianna
Weight: 120
Name 3: Karl
Weight: 109
Name 4: Chuck
Weight: 145
Name 5: Stephanie
Weight: 130
Name 6: Roger
Weight: 199
Name 7: Zelda
Weight: 145
Name 8: Serdar
Weight: 185
Name 9: Max
Weight: 110
Name 10: Sabrina
Weight: 80
Name 11: Mark
Weight: 200
Name 12: Akin
Weight: 190
Name 13: Bruce
Weight: 170
Name 14: Robert
Weight: 192
Name 15: Steve
Weight: 243
Preorder: Mike Brianna Akin Karl Chuck Bruce Max Mark Stephanie Roger Robert Serdar Sabrina Zelda Steve 
Inorder: Akin Brianna Bruce Chuck Karl Mark Max Mike Robert Roger Sabrina Serdar Stephanie Steve Zelda 
Postorder: Akin Bruce Chuck Mark Max Karl Brianna Robert Sabrina Serdar Roger Steve Zelda Stephanie Mike 
Tree height: 5
Leaf count: 6
Enter name to search: Serdar
Found: Serdar, Weight: 185
Lowest weight: 80
First alphabetically: Akin

*/