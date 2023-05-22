#include <iostream>
#include <fstream>
#include <string>
#include "DeliveryOrder.h"
using namespace std;

// Make sure you initialize the static variables taxRate to be 0.09 and the deliveryRate to be $1.5 for the class. Initialization of static variables need to be written in the source file.
const float taxRate = 0.09; // const taxRate, will be initialized as 0.09
const float deliveryRate = 1.5; // const deliveryRate, will be initialized as 1.5
static int orderCount = 0; // orderCount, which is used to calculate how many orders are placed
static float orderBalance = 0;

//// CONSTRUCTOR ////
// The constructor will initialize customer's name, date of the order (month/day/year), phone number, and number of miles of the delivery from the parameters. It will initialize the orderBalance to be 0, then increase the orderCount so that we can count how many orders are created
DeliveryOrder::DeliveryOrder(string name, string date, string phone, float miles) {
    // The constructor will initialize customer's name, date of the order (month/day/year), phone number, and number of miles of the delivery from the parameters. It will initialize the orderBalance to be 0, then increase the orderCount so that we can count how many orders are created
    DeliveryOrder::orderBalance=0;
    DeliveryOrder::orderCount++;
}

//// DESTRUCTOR ////
// The destructor will output a string "DeliveryOrder destroyed.\n".
DeliveryOrder::~DeliveryOrder() {
    DeliveryOrder::orderCount--;
    cout << "DeliveryOrder destroyed.\n";
}

//// RECEIPT() ////
// constant receipt() function that will print out the order receipt
const void DeliveryOrder::receipt() {
    cout << "Order Detail:" << "\n";
    cout << "\tName: " << name << "\n";
    cout << "\tDate: " << date << "\n";
    cout << "\tPhone: " << phone << "\n";
    cout << "\tOrder Balance: $" << orderBalance << endl;
}

//// GETTOTALBALANCE() ////
// constant getTotalBalance() function that will return the total balance(with delivery fee and tax)
const float DeliveryOrder::getTotalBalance() {
    orderBalance *= (1 + taxRate) + miles * deliveryRate; // need to pass orderBalance by reference?
    return orderBalance;
};

//// GETORDERCOUNT() ////
// static getOrderCount() function that will return the orderCount
int DeliveryOrder::getOrderCount() {
    return orderCount;
};

//// ADDTOBALANCE() //// 
static void addToBalance(float amount) {
    orderBalance += amount;
};

//// GETORDERBALANCE ////
static float getOrderBalance() {
    return orderBalance;
}