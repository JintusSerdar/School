#include "FoodOrder.h"
#include "InvalidInput.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Constructor
FoodOrder::FoodOrder(const string& _name, const string& _date, const string& _phone, float _miles, const string& _restaurantName)
        : DeliveryOrder(_name, _date, _phone, _miles), restaurantName(_restaurantName) {}

// Destructor
FoodOrder::~FoodOrder() {
    cout << "FoodOrder destroyed.\n";
}

// Overrides
void FoodOrder::receipt() const {
    DeliveryOrder::receipt(); // Call base class receipt function
    cout << "\tFood Count: " << foodCount << endl;
}

float FoodOrder::VIPdiscount() {
    if (orderBalance > 50) {
        return 0.8;
    } else if (orderBalance > 30) {
        return 0.9;
    } else if (orderBalance > 20) {
        return 0.95;
    } else {
        return 1.0;
    }
}

// Food adder
void FoodOrder::addFood(const string& mainCourse, int sideCount, bool addSoup) {
    float costPerMeal = 0.0;

    if (mainCourse == "Thick Cauliflower Steaks") {
        costPerMeal = 15.0;
    } else if (mainCourse == "Rack of Lamb") {
        costPerMeal = 38.0;
    } else if (mainCourse == "Organic Scottish Salmon") {
        costPerMeal = 23.0;
    } else if (mainCourse == "Grilled Lobster Risotto") {
        costPerMeal = 46.0;
    } else {
        throw InvalidInput(mainCourse);
    }

    // Additional costs
    costPerMeal += sideCount * 6.0;
    if (addSoup) {
        costPerMeal += 5.0;
    }

    // Update order details
    orderBalance += costPerMeal;
    foodCount++;
}
