#include <iostream>
#include <fstream>
#include <string>
#include "DeliveryOrder.h"
#include "FoodOrder.h"
#include "InvalidInput.h"
using namespace std;

int foodCount = 0;

//// CONSTRUCTOR ////
// The constructor of FoodOrder takes the same parameters as DeliveryOrder's constructor and also takes in an extra string to initialize the member attribute restaurantName.
FoodOrder::FoodOrder(string n, string d, string p, float m, string restaurant)
    :DeliveryOrder(n, d, p, m) // eplicitly calling the base calss's constructor
{
    restaurantName = restaurant; // initialize the member attribute restaurantName
}

//// DESTRUCTOR ////
FoodOrder::~FoodOrder() // implicitly calling the base class's destructor
{
    cout << "FoodOrder destroyed.\n";
}

const void FoodOrder::receipt() {
    // Make sure you call the receipt() function of the DeliveryOrder class instead of rewriting the same piece of code again.
    DeliveryOrder::receipt();
    // FoodOrder will override the receipt() function by adding one extra line to the receipt as following:
    cout << "\tFood Count: " << foodCount << endl;
}

// It will also override the VIPdiscount() function as it's required for pure virtual functions. The discount function will
float VIPdiscount() {
    if (DeliveryOrder::getOrderBalance() > 50) // return 0.85 if the orderBalance(without tax and shipping cost) is greater than 50
    {
        return 0.85;
    }
    else if (DeliveryOrder::getOrderBalance() > 30) // return 0.9 if the orderBalance(without tax and shipping cost) is greater than 30
    {
        return 0.9;
    }
    else if (DeliveryOrder::getOrderBalance() > 20) // return 0.95 if the orderBalance(without tax and shipping cost) is greater than 20
    {
        return 0.95;
    }
    else // return 1 if the orderBalance(without tax and shipping cost) is less than or equal to 20
    {
        return 1;
    }
}

//// ADDFOOD() ////
void addFood(string main/*name of main course*/, int side=0/*# of sides*/, bool soup=0/*add soup?*/) {
    
    // You will do string comparison to match the meal and if the passed in meal doesn't match any of the meal listed on the menu, throw the InvalidInput exception with meal name as the parameter. 

    // the below "for loop" converts main to lowercase
    string foodName = main;
    for (int i=0; i<foodName.length(); i++) {
        foodName[i] = tolower(foodName[i]);
    }

    float foodPrice = 0; // the price of the item(s) being added to order w/o tax or fees

    // then compares foodName without case mattering
    if (foodName == "thick cauliflower steaks") // Thick Cauliflower Steaks: $15
    {
        foodPrice = 15;
    }
    else if (foodName == "rack of lamb") // Rack of Lamb: $38
    {
        foodPrice = 38;
    }
    else if (foodName == "organic scottish salmon") // Organic Scottish Salmon: $23
    {
        foodPrice = 23;
    }
    else if (foodName == "grilled lobster risotto") // Grilled Lobster Risotto: $46
    {
        foodPrice = 46;
    }
    // else // invalid entry
    // {
    //     throw InvalidInput(foodName); // throw the InvalidInput exception and pass in the food name
    // }
    
    /// ADD-ON COSTS ///
    // Adding soup costs $5
    if (soup) {
        foodPrice += 5;
    }
    // each additional side costs $6
    foodPrice += 6 * side;

    // At the end of the function make sure you update the foodCount and add the cost of this food order to the orderBalance of the order.
    foodCount++; // update the foodCount
    DeliveryOrder::addToBalance(foodPrice); // add the cost of this food order to the orderBalance of the order

}