#ifndef MINION_H
#define MINION_H

#include <iostream>

class Minion {

private:
    std::string name;
    float height;
    int eyes;
    int bananasOwned;
    static int minionCount;

public:

    // Statics
    static void printMinionCount();

    // Constructor
    Minion(std::string name, float height, int eyes, int bananasOwned);

    // Operator-overloading
    bool operator>(const Minion& other) const;
    bool operator<(const Minion& other) const;
    Minion& operator++();  // Pre increment
    Minion operator++(int);  // Post increment
    friend std::ostream& operator<<(std::ostream& out, const Minion& minion);

    // Getters
    int getBananas() const;
    std::string getName() const;
};

#endif
