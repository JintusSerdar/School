#ifndef INVALID_INPUT_H
#define INVALID_INPUT_H

#include <iostream>
#include <string>

// InvalidInput class represents an exception for invalid input
class InvalidInput {
private:
    const std::string message;

public:
    // Constructor
    InvalidInput(const std::string& input)
            : message("Invalid input \"" + input + "\".\n") {}
            
    // Prints the error reason
    void reason() const {
        std::cout << message << std::endl;
    }
};

#endif
