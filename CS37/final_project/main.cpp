#include "Account.h"
#include "BobaOrder.h"
#include "DeliveryOrder.h"
#include "FoodOrder.h"
#include "InvalidInput.h"

#include <iomanip>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Applies discount to special accounts
float applyDiscount(DeliveryOrder* order, const Account& account);

int main() {
    // Create constant owner account
    const Account StuartAccount("Stuart", "Owner");

    // Create VIP account
    Account KevinAccount("Kevin", "VIP");

    // Create regular account
    Account BobAccount("Bob");

    // Create a DeliveryOrder pointer for polymorphism
    DeliveryOrder* orderPtr;


    // Kevin's order
    cout << "Kevin is placing order.\n";

    // Create a BobaOrder
    BobaOrder KevinOrder("Kevin", "11/20/2023", "123-456-0000", 10.4, "M Tea");

    try {
        // Add drink orders
        KevinOrder.addDrink("Green Tea Latte");
        KevinOrder.addDrink("Brown Sugar Pearl Milk", false);
        KevinOrder.addDrink("Brown Sugar Boba Milk", false, 2);
        KevinOrder.addDrink("Iron Goddess"); // Invalid drink

    } catch (const InvalidInput& e) {
        e.reason();
        cout << "Not serving requested drinks. Drink order ignored.\n\n";
    }

    // Formatting number output
    cout << std::fixed << std::setprecision(2);

    // Print receipt
    KevinOrder.receipt();

    // Output balance
    cout << "Balance: $" << KevinOrder.getTotalBalance() << endl;

    // Apply discount and output discounted balance
    orderPtr = &KevinOrder;
    cout << "Discounted Balance: $" << applyDiscount(orderPtr, KevinAccount) << endl;

    cout << "\n\n";


    // Stuart's order
    cout << "Stuart is placing order.\n";

    // Create a FoodOrder
    FoodOrder StuartOrder("Stuart", "11/20/2023", "123-456-1111", 25.5, "Tavern Green");

    try {
        // Add food orders
        StuartOrder.addFood("Thick Cauliflower Steaks", 1, true);
        StuartOrder.addFood("Organic Scottish Salmon", 0, false);
        StuartOrder.addFood("Rack of Lamb", 0, true);

    } catch (const InvalidInput& e) {
        e.reason();
        cout << "Not serving requested food. Food order ignored.\n\n";
    }

    // Print receipt
    StuartOrder.receipt();

    // Output balance
    cout << "Balance: $" << StuartOrder.getTotalBalance() << endl;

    // Apply discount and output discounted balance
    orderPtr = &StuartOrder;
    cout << "Discounted Balance: $" << applyDiscount(orderPtr, StuartAccount) << endl;

    cout << "\n\n";


    // Bob's order
    cout << "Bob decided to log in to his account and see whether he can afford ordering the same order as Stuart.\n";

    try {
        // Bob is trying to place the same order as Stuart
        // Use the same order object created for Stuart
        // Print receipt
        StuartOrder.receipt();

        // Output balance
        cout << "Balance: $" << StuartOrder.getTotalBalance() << endl;

        // Apply discount with Bob's account and output discounted balance
        orderPtr = &StuartOrder;
        cout << "Discounted Balance: $" << applyDiscount(orderPtr, BobAccount) << endl;

        // Bob is upset and decides to cancel the order
        cout << "Bob upset, cancelling order :(\n\n";

    } catch (const InvalidInput& e) {
        e.reason();
        cout << "Not serving requested food. Food order ignored.\n\n";
    }

    // Output the total number of orders placed
    cout << "Total order placed: " << DeliveryOrder::getOrderCount() << "\n\n";

}

float applyDiscount(DeliveryOrder* order, const Account& account) {
    string status = account.getStatus();
    if (status == "Owner") {
        return order->getTotalBalance() * 0.1;
    } else if (status == "VIP") {
        return order->VIPdiscount() * order->getTotalBalance();
    } else {
        return order->getTotalBalance();
    }
}