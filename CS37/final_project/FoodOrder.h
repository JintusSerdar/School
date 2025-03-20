#ifndef FOOD_ORDER_H
#define FOOD_ORDER_H

#include "DeliveryOrder.h"

#include <string>

// FoodOrder class represents an order for food delivery
class FoodOrder : public DeliveryOrder {
private:
    std::string restaurantName;
    int foodCount;

public:
    // Constructor
    FoodOrder(const std::string& _name, const std::string& _date, const std::string& _phone, float _miles, const std::string& _restaurantName);

    // Destructor
    ~FoodOrder();

    // Overrides
    void receipt() const;
    float VIPdiscount();

    // Food adder
    void addFood(const std::string& mainCourse, int sideCount = 0, bool addSoup = false);
};

#endif // FOOD_ORDER_H
