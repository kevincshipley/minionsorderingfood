// NOTE: this is the Base Class
// is this also considered an Abstract Class?

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

class DeliveryOrder {
    
    // Class DeliveryOrder will have the following member attributes:

    //// PROTECTED ////
    protected: // these can be accessed by Derived Classes only
    static float orderBalance; // orderBalance(float, doesn't include delivery fee and tax)

    //// PRIVATE ////
    private:
    string name; // customer's name(string)
    string date;// date of the order(string)
    string phone;// phone number(string)
    float miles;// number of miles for the delivery(float)

    // The class DeliveryOrder also has three static members including orderCount, which is used to calculate how many orders are placed, and two constant variables taxRate and deliveryRate.

    /* Static Members
    A static member is a “class-wide” member shared by all objects of the class.
    Note: Because static members are in class scope, so we use classname:: to access them.

    - must be initialized exactly once.
    - initialized by compiler before main() runs, at compile time.
    - Fundamental-type static data members are initialized by default to 0
    - A constant type static members needs to be initialized explicitly
    - can only access static variables
    */

    static int orderCount; // orderCount, which is used to calculate how many orders are placed
    static const float taxRate; // const taxRate, will be initialized as 0.09
    static const float deliveryRate; // const deliveryRate, will be initialized as 1.5

    //// PUBLIC ////
    public:
    // Class DeliveryOrder will have a constructor, a destructor, and four functions:

    //// CONSTRUCTOR ////
    DeliveryOrder(string name, string date, string phone, float miles);

    //// DESTRUCTOR ////
    ~DeliveryOrder();

    //// RECEIPT() ////
    // constant receipt() function that will print out the order receipt
    const void receipt();

    //// GETTOTALBALANCE() ////
    // constant getTotalBalance() function that will return the total balance(with delivery fee and tax)
    const float getTotalBalance();

    //// GETORDERCOUNT() ////
    // static getOrderCount() function that will return the orderCount
    static int getOrderCount();

    //// VIPDISCOUNT() ////
    // pure virtual function VIPdiscount() that will calculate and return the discount for the order
    virtual float VIPdiscount() {
        // this will return a discount rate to multiple orderBalance by
        // rate is based on the type of Order being placed (Boba vs. Food) which will have a determining factor setting the discount rate
        return 1;
    };

    //// ADDTOBALANCE() //// 
    static void addToBalance(float amount);

    //// GETORDERBALANCE ////
    static float getOrderBalance();

};

#endif