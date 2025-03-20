#include <iostream>
#include <string>
using namespace std;

string runLengthEncode(const string& input) {
    if (input.empty()) return "";
    
    string encoded;
    int count = 1;
    
    for (size_t i = 1; i <= input.length(); i++) {
        char currentChar = input[i];        // Current character we're looking at
        char previousChar = input[i-1];     // Previous character in the string
        
        // If we're still in the string bounds and current character matches previous character
        if (i < input.length() && currentChar == previousChar) {
            count++;
        }
        // If character changes or we're at the end, add the count and character to result
        else {
            encoded += to_string(count) + previousChar;
            count = 1;
        }
    }
    
    return encoded;
}

int main() {
    string input;
    cout << "Enter a string to encode: ";
    getline(cin, input);
    
    string encoded = runLengthEncode(input);
    
    cout << "Encoded string: " << encoded << endl;
    
    // Calculate and display compression rate
    double compressionRate = (1.0 - static_cast<double>(encoded.length()) / input.length()) * 100;
    cout << "Compression rate: " << compressionRate << "%" << endl;
    
    return 0;
}