#include <iostream>
#include <fstream>
#include <string>
#include "DeliveryOrder.h"
#include "BobaOrder.h"
#include "InvalidInput.h"
using namespace std;

int drinksCount=0;

/// CONSTRUCTOR ///
BobaOrder::BobaOrder(string n, string d, string p, float m, string shop)
    :DeliveryOrder(n, d, p, m) // eplicitly calling the base calss's constructor
{
    // The constructor of BobaOrder should take the same parameters as DeliveryOrder's constructor and an extra string to initialize the member attribute shopName.
    shopName = shop;
}

/// DESTRUCTOR ///
BobaOrder::~BobaOrder() // implicitly calling the base class's destructor
{
    cout << "BobaOrder destroyed.\n";
}

const void BobaOrder::receipt() {
    // Make sure you call the receipt() function of the DeliveryOrder class instead of rewriting the same piece of code again.
    DeliveryOrder::receipt();
    // BobaOrder will override the receipt() function by adding one extra line to the receipt as following:
    cout << "\tDrinks Count: " << drinksCount << endl;
}

//// VIPDISCOUNT() ////
float VIPdiscount() {
        if (drinksCount > 10) // return 0.85 if the number of drinks is greater than 10
        {
            return 0.85;
        }
        else if (drinksCount > 5) // return 0.9 if the number of drinks is greater than 5
        {
            return 0.9;
        }
        else if (drinksCount > 2) // return 0.95 if the number of drinks is greater than 2
        {
            return 0.95;
        }
        else // return 1 if the number of drinks is less than or equal to 2
        {
            return 1;
        }
    };

//// ADDDRINK() ////
void addDrink(string drinkName, bool addBoba = 1 /*default Add Boba? to true*/, int count=1 /*default # same drinks to order*/)
{
    // You will do string comparison to match the drinks with the parameter. If the passed in drink doesn't match any of the available drinks, throw the InvalidInput exception and pass in the drink name. Adding boba will cost $1.5 per drink, and make sure you multiply the passed in count in case one wants to order more than one of the same drink. For example, if Kevin orders 2 Green Tea Latte with bobas, the cost will be ($5.8 + $1.5) * 2.

    // the below "for loop" converts drinkName to lowercase
    string drink = drinkName;
    for (int i=0; i<drink.length(); i++) {
        drink[i] = tolower(drink[i]);
    }
    
    // Menu:
    // Green Tea Latte: $5.8
    // Brown Sugar Boba Milk: $7.8
    // Brown Sugar Pearl Milk: $9.8

    // Adding boba will cost $1.5 per drink, and make sure you multiply the passed in count in case one wants to order more than one of the same drink.

    float drinkPrice=0; // initialize drinkPrice to calc price of each drink + boba if ordered

    // then compares drinkName without case mattering
    if (drink == "green tea latte") // Green Tea Latte: $5.8
    {
        drinkPrice = 5.8;
    }
    else if (drink == "brown sugar boba milk") // Brown Sugar Boba Milk: $7.8
    {   
        drinkPrice = 7.8;
    }
    else if (drink == "brown sugar pearl milk") // Brown Sugar Pearl Milk: $9.8
    {
        drinkPrice = 9.8;
    }
    // else // invalid entry
    // {
    //     throw InvalidInput(drinkName); // throw the InvalidInput exception and pass in the drink name
    // }
    
    // add boba?
    if (addBoba) {
        drinkPrice += 1.5;
    }
    // multiple price of drink by amount ordered
    drinkPrice = drinkPrice * count;

    // At the end of the function make sure you add the number of drinks to the drinksCount and also add the cost of this drink order to the orderBalance of the order.
    drinksCount += count; // increase drinksCount by how many drinks ordered 
    DeliveryOrder::addToBalance(drinkPrice); // add the cost of this drink order to the orderBalance of the order
    
};