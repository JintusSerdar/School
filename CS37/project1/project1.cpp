#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/* The userAccount struct represents user account information, 
including username, nationality, age, and account balance. */
struct userAccount {
    string username;
    string nationality;
    int age;
    double accountBalance;
};

int main() {
    userAccount users[20]; 
    int userCount = 0;

    // Instruction
    cout << "Please enter information to database in the format of <username> <nationality> <age> <accountBalance>, separated each user by a newline:" << endl;

    // Get user input
    while (userCount < 20 && cin >> users[userCount].username >> users[userCount].nationality >> users[userCount].age >> users[userCount].accountBalance) {
        userCount++;
    }

    if (userCount >= 20) {
    cout << "\nMaximum number of users (20) reached.\n" << endl;
    }

    // Questions and Answers
    double highestBalance = 0;
    double totalBalance = 0;
    int swedishCount = 0;
    string hasYoungerThan21 = "No";

    for (int i = 0; i < userCount; i++) {
        // Q1: What is the highest account balance among all users?
        if (users[i].accountBalance > highestBalance) {
            highestBalance = users[i].accountBalance;
        }

        // Q2: What's the sum of account balance of all users?
        totalBalance += users[i].accountBalance;

        // Q3: How many users come from Sweden?
        if (users[i].nationality == "Swedish") {
            swedishCount++;
        }

        // Q4: Do we have any user younger than 21?
        if (users[i].age < 21) {
            hasYoungerThan21 = "Yes";
        }
    }

    // Output the answers
    cout << fixed << setprecision(1);
    cout << "Q: What is the highest account balance among all users?" << endl;
    cout << "A: $" << highestBalance << endl;

    cout << "Q: What's the sum of account balance of all users?" << endl;
    cout << "A: $"  << setprecision(2) << totalBalance << endl;

    cout << "Q: How many users come from Sweden?" << endl;
    cout << "A: " << swedishCount << endl;

    cout << "Q: Do we have any user younger than 21?" << endl;
    cout << "A: " << hasYoungerThan21 << endl;

    return 0;
}
