#ifndef BOBA_ORDER_H
#define BOBA_ORDER_H

#include "DeliveryOrder.h"

#include <string>

// BobaOrder class represents an order for boba drinks
class BobaOrder : public DeliveryOrder {
private:
    std::string shopName;
    int drinksCount;

public:
    // Constructor
    BobaOrder(const std::string& _name, const std::string& _date, const std::string& _phone, float _miles, const std::string& _shopName);

    // Destructor
    ~BobaOrder();

    // Overrides
    void receipt() const;
    float VIPdiscount();

    // Boba Drink Adder
    void addDrink(const std::string& drink, bool addBoba = true, int count = 1);
};

#endif // BOBA_ORDER_H
