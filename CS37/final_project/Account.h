#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

// Account class represents a user account in the system
class Account {
private:
    std::string username;
    std::string status;

public:
    // Constructor
    Account(const std::string& _username, const std::string& _status = "Regular");

    // Destructor
    ~Account();

    // Getters
    std::string getStatus() const;
};

#endif // ACCOUNT_H
