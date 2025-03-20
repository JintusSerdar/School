#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

bool isNumeric(const string& str) {
    istringstream iss(str);
    double num;
    iss >> noskipws >> num;
    return iss.eof() && !iss.fail();
}

int main() {
    string sentence;
    cout << "Sentence: ";
    getline(cin, sentence);

    istringstream iss(sentence);
    string word;

    while (iss >> word) {
        if (isNumeric(word)) {
            double num = stod(word);
            cout << num * 2 << endl;
        } else {
            cout << word << endl;
        }
    }

    return 0;
}