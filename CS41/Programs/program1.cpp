#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Node struct for the linked list
struct Node {
    double data;
    Node* next;
    Node(double value) : data(value), next(nullptr) {}
};

// Stack class implemented using a linked list
class Stack {
private:
    Node* top;  // Pointer to the top of the stack
    int count;  // Number of elements in the stack

public:
    Stack() : top(nullptr), count(0) {}  // Constructor

    // Push a new element onto the stack
    void push(double value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        count++;
    }

    // Pop the top element from the stack
    double pop() {
        if (isEmpty()) {
            throw runtime_error("Error: Stack is empty");
        }
        double value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
        return value;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return count == 0;
    }

    // Destructor 
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Function to evaluate RPN expression
double evaluateRPN(const string& expression) {
    Stack stack;
    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (token == "=") break;  // End of expression

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Operator found, pop two operands and perform the operation
            if (stack.isEmpty()) throw runtime_error("Error: Too many operators");
            double b = stack.pop();
            if (stack.isEmpty()) throw runtime_error("Error: Too many operators");
            double a = stack.pop();

            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") {
                if (b == 0) throw runtime_error("Error: Division by zero");
                stack.push(a / b);
            }
        } else {
            // Attempt to convert token to a number and push onto the stack
            try {
                double num = stod(token);
                stack.push(num);
            } catch (const invalid_argument&) {
                throw runtime_error("Error: Invalid token '" + token + "'");
            }
        }
    }

    // Check for valid expression result
    if (stack.isEmpty()) throw runtime_error("Error: Empty expression");
    double result = stack.pop();
    if (!stack.isEmpty()) throw runtime_error("Error: Too many operands");

    return result;
}

int main() {
    string input;

    // Main program loop
    while (true) {
        cout << "Enter RPN expression (or 0 to exit): ";
        getline(cin, input);

        if (input == "0") break;  // Exit condition

        try {
            double result = evaluateRPN(input);
            cout << result << endl;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}

/* Output:
Enter RPN expression (or 0 to exit): 10 15
Error: Too many operands
Enter RPN expression (or 0 to exit): 10 15 +
25
Enter RPN expression (or 0 to exit): 10 15 -
-5
Enter RPN expression (or 0 to exit): 2.5 3.5 +
6
Enter RPN expression (or 0 to exit): 10 0 /
Error: Division by zero
Enter RPN expression (or 0 to exit): 10 20 * /
Error: Too many operators
Enter RPN expression (or 0 to exit): 10 20 30 /
Error: Too many operands
Enter RPN expression (or 0 to exit): 10 20 30 +
Error: Too many operands
Enter RPN expression (or 0 to exit): -10 -30 -
20
Enter RPN expression (or 0 to exit): 100 10 50 25 / * - -2 /
-40
Enter RPN expression (or 0 to exit): 20 -2 * 10 -
-50
Enter RPN expression (or 0 to exit): 10 10 10 - *
0
Enter RPN expression (or 0 to exit): 0
*/
