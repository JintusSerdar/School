#include "Account.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Constructor
Account::Account(const string& _username, const string& _status)
        : username(_username), status(_status) {}

// Destructor
Account::~Account() {
    cout << "Account removed.\n";
}

// Getters
string Account::getStatus() const {
    return status;
}
