#include "Minion.h"

int Minion::minionCount = 0;

// Constructor
Minion::Minion(std::string name, float height, int eyes, int bananasOwned)
        : name(name), height(height), eyes(eyes), bananasOwned(bananasOwned) {
    Minion::minionCount++;
}

// Operator-overloading
bool Minion::operator>(const Minion& other) const {
    return this->height > other.height;
}

bool Minion::operator<(const Minion& other) const {
    return this->height < other.height;
}

Minion& Minion::operator++() {
    this->bananasOwned++;
    return *this;
}

Minion Minion::operator++(int) {
    Minion temp = *this;
    this->bananasOwned++;
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Minion& minion) {
    out << "The minion " << minion.getName() << " is " << minion.height << " inches tall, has " << minion.eyes << " eye(s), and owns " << minion.bananasOwned << " banana(s)." << std::endl;
    return out;
}

// Getters
int Minion::getBananas() const {
    return this->bananasOwned;
}

std::string Minion::getName() const {
    return this->name;
}

void Minion::printMinionCount() {
    std::cout << Minion::minionCount << " minions created." << std::endl;
}
