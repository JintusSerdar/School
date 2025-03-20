#include "DeliveryOrder.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int DeliveryOrder::orderCount = 0;
const float DeliveryOrder::taxRate = 0.09;
const float DeliveryOrder::deliveryRate = 2.0;

// Constructor
DeliveryOrder::DeliveryOrder(const string& _name, const string& _date, const string& _phone, float _miles)
        : name(_name), date(_date), phone(_phone), miles(_miles), orderBalance(0.0) {
    orderCount++;
}

// Destructor
DeliveryOrder::~DeliveryOrder() {
    cout << "DeliveryOrder destroyed.\n";
}

void DeliveryOrder::receipt() const {
    cout << "Order Detail:" << "\n";
    cout << "\tName: " << name << "\n";
    cout << "\tDate: " << date << "\n";
    cout << "\tPhone: " << phone << "\n";
    cout << "\tOrder Balance: $" << orderBalance << endl;
}

// Getters
float DeliveryOrder::getTotalBalance() const {
    return orderBalance * (1 + taxRate) + miles * deliveryRate;
}

int DeliveryOrder::getOrderCount() {
    return orderCount;
}
