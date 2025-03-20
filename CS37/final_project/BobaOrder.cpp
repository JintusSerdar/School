#include "BobaOrder.h"
#include "InvalidInput.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Constructor
BobaOrder::BobaOrder(const string& _name, const string& _date, const string& _phone, float _miles, const string& _shopName)
        : DeliveryOrder(_name, _date, _phone, _miles), shopName(_shopName){}

// Destructor
BobaOrder::~BobaOrder() {
    cout << "BobaOrder destroyed.\n";
}

// Overrides
void BobaOrder::receipt() const {
    DeliveryOrder::receipt(); // Call base class receipt function
    cout << "\tDrinks Count: " << drinksCount << endl;
}

float BobaOrder::VIPdiscount() {
    if (drinksCount > 10) {
        return 0.8;
    } else if (drinksCount > 5) {
        return 0.9;
    } else if (drinksCount > 2) {
        return 0.95;
    } else {
        return 1.0;
    }
}

// Boba Drink Adder
void BobaOrder::addDrink(const string& drink, bool addBoba, int count) {
    float costPerDrink = 0;

    if (drink == "Green Tea Latte") {
        costPerDrink = 5.8;
    } else if (drink == "Brown Sugar Boba Milk") {
        costPerDrink = 7.8;
    } else if (drink == "Brown Sugar Pearl Milk") {
        costPerDrink = 9.8;
    } else {
        throw InvalidInput(drink);
    }

    if (addBoba) {
        costPerDrink += 1; // Adding boba costs $1 per drink
    }

    float totalCost = costPerDrink * count;

    // Update order details
    orderBalance += totalCost;
    drinksCount += count;
}