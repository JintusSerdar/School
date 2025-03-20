#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include <string>

// DeliveryOrder is an abstract class that represents a general delivery order
class DeliveryOrder {
private:
    std::string name;
    std::string date;
    std::string phone;
    float miles;
    static int orderCount;
    static const float taxRate;
    static const float deliveryRate;

protected:
    float orderBalance;

public:
    // Constructor
    DeliveryOrder(const std::string& _name, const std::string& _date, const std::string& _phone, float _miles);

    // Destructor
    ~DeliveryOrder();

    // Prints order details
    void receipt() const;

    // Getters
    float getTotalBalance() const;
    static int getOrderCount();

    // Pure Virtual
    // Calculate discounts for VIP accounts
    virtual float VIPdiscount() = 0;
};

#endif  // DELIVERY_ORDER_H
