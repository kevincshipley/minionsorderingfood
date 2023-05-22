#include <iostream>
#include <fstream>
#include <string>
#include "DeliveryOrder.h"
using namespace std;

#ifndef BOBAORDER_H
#define BOBAORDER_H

// BobaOrder should inherit from DeliveryOrder with public inheritance.
// NOTE: Public inheritance will give class BobaOrder access to only public and protected members of class DeliveryOrder directly
class BobaOrder : public DeliveryOrder {

    //// PRIVATE ////
    private:
    // it has two additional member attributes, shopName and drinksCount.
    string shopName;
    int drinksCount;

    //// PUBLIC ////
    public:
    //// CONSTRUCTOR ////
    BobaOrder(string name, string date, string phone, float miles, string shopName);
    /// DESTRUCTOR ///
    ~BobaOrder();


    //// RECEIPT() ////
    // constant receipt() function that will print out the order receipt
    const void receipt();

    //// VIPDISCOUNT() ////
    // It will also override the VIPdiscount() function as it's required for pure virtual functions.
    float VIPdiscount();
        // return 0.85 if the number of drinks is greater than 10
        // return 0.9 if the number of drinks is greater than 5
        // return 0.95 if the number of drinks is greater than 2
        // return 1 if the number of drinks is less than or equal to 2

    //// ADDDRINK() ////
    /* BobaOrder also has a new function addDrink() which will take in the name of the drink, a boolean default to true indicating whether one wants to add boba to the drink, and a count default to 1 indicating how many of the same drink one wants to order. There are three drinks available for people to order from:
    > Green Tea Latte: $5.8
    > Brown Sugar Boba Milk: $7.8
    > Brown Sugar Pearl Milk: $9.8

    You will do string comparison to match the drinks with the parameter. If the passed in drink doesn't match any of the available drinks, throw the InvalidInput exception and pass in the drink name. Adding boba will cost $1.5 per drink, and make sure you multiply the passed in count in case one wants to order more than one of the same drink. For example, if Kevin orders 2 Green Tea Latte with bobas, the cost will be ($5.8 + $1.5) * 2.

    At the end of the function make sure you add the number of drinks to the drinksCount and also add the cost of this drink order to the orderBalance of the order.*/
    
    void addDrink(string drinkName, bool addBoba = 1 /*default to true*/, int count=1 /*default count of same drinks to 1*/);

};

#endif