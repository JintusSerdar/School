#include <iostream>
#include <fstream>
#include "Minion.h"

int main() {
    // Read file and create minions
    std::ifstream file("minions.txt");

    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    std::string name;
    float height;
    int eyes;
    int bananasOwned;

    file >> name >> height >> eyes >> bananasOwned;
    const Minion minion1(name, height, eyes, bananasOwned);

    file >> name >> height >> eyes >> bananasOwned;
    Minion minion2(name, height, eyes, bananasOwned);

    file >> name >> height >> eyes >> bananasOwned;
    Minion minion3(name, height, eyes, bananasOwned);

    file.close();

    //Find the taller minion
    if (minion1 > minion2) {
        std::cout << minion1.getName() << " is taller than " << minion2.getName();
    }
    if (minion2 < minion3) {
        std::cout << minion3.getName() << " is taller than " << minion2.getName();
    }
    std::cout << std::endl << std::endl;

    // Output Minion2 information and give bananas
    std::cout << minion2;
    std::cout << minion2.getName() << " getting bananas.\n";
    std::cout << "The minion now has " << (++(++minion2)).getBananas() << " banana(s).\n" << std::endl;

    // Output Minion3 information and give bananas
    std::cout << minion3;
    std::cout << minion3.getName() << " getting bananas.\n";
    std::cout << "Before getting bananas, the minion had " << minion3++.getBananas() << " banana(s).\n";
    std::cout << "After getting bananas, the minion has " << minion3.getBananas() << " banana(s).\n" << std::endl;

    // Print minion count
    Minion::printMinionCount();

    return 0;
}
