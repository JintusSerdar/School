#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

const int TABLESIZE = 211; // Prime number for hashtable size

// Variable structure for hash table
struct Variable {
    string name;
    int value;
    int scope;
    Variable* next;
    Variable(string n, int v, int s) : name(n), value(v), scope(s), next(nullptr) {}
};

Variable* hashTable[TABLESIZE];

int currentScope = 0; // Tracks current scope level
int lineNumber = 0;   // Tracks line number in input file

// generates an index based on the variable name
int hashFunction(string varName) {
    int sum = 0;
    for (int i = 0; i < varName.length(); i++) {
        sum += ((int)varName[i]) * (i + 1);
    }
    return sum % TABLESIZE;
}

// Insert variable into the hash table
void insertVariable(string varName, int value) {
    int index = hashFunction(varName);
    Variable* newVar = new Variable(varName, value, currentScope);
    newVar->next = hashTable[index];
    hashTable[index] = newVar;
}

// Find the most recent variable with the given name and scope
Variable* findVariable(string varName) {
    int index = hashFunction(varName);
    Variable* curr = hashTable[index];
    Variable* foundVar = nullptr;
    int highestScope = -1;

    while (curr) {
        if (curr->name == varName && curr->scope <= currentScope) {
            if (curr->scope > highestScope) { // Keep track of the closest scope
                highestScope = curr->scope;
                foundVar = curr;
            }
        }
        curr = curr->next;
    }
    return foundVar;
}

// Remove all variables from the current scope
void removeScopeVariables() {
    for (int i = 0; i < TABLESIZE; i++) {
        Variable* curr = hashTable[i];
        Variable* prev = nullptr;

        while (curr) {
            if (curr->scope == currentScope) {
                // Delete variable if it's in the current scope
                if (prev) {
                    prev->next = curr->next;
                } else {
                    hashTable[i] = curr->next;
                }
                Variable* temp = curr;
                curr = curr->next;
                delete temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

// Check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

// Evaluate an expression and return the result
int evaluateExpression(string expr, bool& errorFlag) {
    istringstream iss(expr);
    string token;
    int result = 0;
    char op = 0;

    while (iss >> token) {
        int value = 0;

        // Check if the token is a variable
        if (isalpha(token[0])) {
            Variable* var = findVariable(token);
            if (var) {
                value = var->value;
            } else {
                errorFlag = true; // Flag if the variable is undefined
                return 0;
            }
        } 
        // Check if the token is a number
        else if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            value = stoi(token);
        } 
        // Handle operator tokens
        else if (isOperator(token[0])) {
            op = token[0];
            continue;
        }

        // Perform the operation
        if (op) {
            switch (op) {
                case '+': result += value; break;
                case '-': result -= value; break;
                case '*': result *= value; break;
                case '/': result /= value; break;
                case '%': result %= value; break;
                case '^': result = pow(result, value); break;
            }
            op = 0; // Reset operator
        } else {
            result = value; // Initial assignment
        }
    }
    return result;
}

int main() {
    // Open the input file
    ifstream infile("HelloWorld.txt");
    string line;

    // Check if the file was opened successfully
    if (!infile.is_open()) {
        cout << "Error: Could not open input file" << endl;
        return 1;
    }

    // Process each line from the file
    while (getline(infile, line)) {
        lineNumber++;
        istringstream iss(line);
        string token;
        if (!(iss >> token)) continue;

        // comments
        if (token == "COM") {
            continue;
        } 
        // start of a new scope
        else if (token == "START") {
            currentScope++;
        } 
        // end of scope
        else if (token == "FINISH") {
            removeScopeVariables();
            currentScope--;
        } 
        // variable declaration
        else if (token == "VAR") {
            string varName;
            if (iss >> varName) {
                int value = 0;
                string eq;

                // Check if there's an assignment right after declaration
                if (iss >> eq && eq == "=") {
                    string expr;
                    getline(iss, expr);
                    bool errorFlag = false;
                    value = evaluateExpression(expr, errorFlag);
                }
                insertVariable(varName, value);
            }
        } 
        // PRINT command
        else if (token == "PRINT") {
            string expr;
            getline(iss, expr);
            expr.erase(0, expr.find_first_not_of(" "));
            bool errorFlag = false;
            int result = evaluateExpression(expr, errorFlag);

            if (!errorFlag) {
                cout << expr << " IS " << result << endl;
            } else {
                cout << expr << " IS UNDEFINED" << endl;
            }
        } 
        // variable assignment or increment/decrement
        else {
            string varName = token;
            string nextToken;

            if (iss >> nextToken) {
                // Handle assignment
                if (nextToken == "=") {
                    string expr;
                    getline(iss, expr);
                    Variable* var = findVariable(varName);

                    if (var) {
                        bool errorFlag = false;
                        int value = evaluateExpression(expr, errorFlag);
                        if (!errorFlag) {
                            var->value = value;
                        }
                    }
                } 
                // increment
                else if (nextToken == "++") {
                    Variable* var = findVariable(varName);
                    if (var) {
                        var->value += 1;
                    }
                } 
                // decrement
                else if (nextToken == "--") {
                    Variable* var = findVariable(varName);
                    if (var) {
                        var->value -= 1;
                    }
                }
            }
        }
    }
    return 0;
}
