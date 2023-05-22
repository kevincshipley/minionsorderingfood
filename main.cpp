#include "DeliveryOrder.h" // DeliveryOrder
#include "FoodOrder.h" // FoodOrder
#include "BobaOrder.h" // BobaOrder
#include "Account.h" // Account
#include "InvalidInput.h" // InvalidInput
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
// #include <cmath>
using namespace std;

//// APPLYDISCOUNT() ////
float applyDiscount(DeliveryOrder, const Account&);
/* 
We will have one function for this system. The function is applyDiscount() which will take in a DeliveryOrder pointer and a constant reference account. The function will return the discounted balance of the order. For example, if the total balance(returned from function getTotalBalance()) is $100 and the discount is 0.1, then this function will return the float 10 which is (100 * 0.1).

The applyDiscount() function will check the account status to determine how to apply the discount:
> If the account status is "Owner", it will apply 90% off to the order, so it will return 0.1 multiply by the delivery balance
> If the account status is "VIP", it will trigger the corresponding VIPdiscount() function of the order depending on whether it's a BobaOrder or a FoodOrder with dynamic binding. It will then take the returned value of VIPdiscount() and multiply with delivery balance then return the result.
> If the account status is "Regular", no discount will be applied and the delivery balance of the order will remain unchanged and returned.
*/

int main () {
    // Finally, it's our main function. We first have three accounts, one constant owner account, one VIP account, and one regular account.

    //// STUART ////
    // Stuart appears to be the secret owner of all the restaurants and boba shops of New York, he will have an owner account the system created for him and he can't change the account, so it's a constant account. The account username will be "Stuart" and the status will be "Owner".
    const Account stuart("Stuart", "Owner");

    //// KEVIN ////
    // Kevin appears to be the secret VIP of all the restaurants and boba shops of New York, and he created his VIP account with username "Kevin" and status "VIP".
    Account kevin("Kevin", "VIP");

    //// BOB ////
    // Bob appears to be a regular customer, who's not aware of Kevin and Stuart's secret identities, created his regular account with username "Bob".
    Account bob("Bob");

    // We will then have a DeliveryOrder pointer that we will later use to point to different orders to allow polymorphism.
    DeliveryOrder* order; // DeliveryOrder base class pointer

    //// KEVIN PLACING ORDER ////
    // Kevin starts to order boba drinks for everyone. Let's first output
    cout << "Kevin placing order.\n";
    // He creates his order with his name "Kevin", date "11/20/2022", phone number "123-456-0000". He's placing order at the shop "M Tea" and looks like the miles for the delivery is 10.4 miles.

    // BobaOrder kOrder("Kevin", "11/20/2022", "123-456-0000", 10.4, "M Tea");
    // order = &kOrder; // DeliveryOrder pointer points to BobaOrder object ???

    BobaOrder kOrder("Kevin", "11/20/2022", "123-456-0000", 10.4, "M Tea");

    // Because each of the addDrink() function could cause exception, let's put all the addDrink() function calls in a try catch block. Catch the InvalidInput exception by reference and trigger the print_reason() function of the exception.
    try {
        kOrder.addDrink("Green Tea Latte"); // Kevin adds his first drink order "Green Tea Latte" with all default choices for this drink
    }
    catch (InvalidInput &) {
        throw InvalidInput("Green Tea Latte");
        cout << "Not serving requested drinks. Drink order ignored.\n\n";
    }
    try {
        kOrder.addDrink("Brown Sugar Pearl Milk", 0); // then his second drink "Brown Sugar Pearl Milk" with no boba
    }
    catch (InvalidInput &) {
        throw InvalidInput("Brown Sugar Pearl Milk");
        cout << "Not serving requested drinks. Drink order ignored.\n\n";
    }
    try {
        kOrder.addDrink("Brown Sugar Boba Milk", 0, 2); // and two more "Brown Sugar Boba Milk" with no boba.
    }
    catch (InvalidInput &) {
        throw InvalidInput("Brown Sugar Boba Milk");
        cout << "Not serving requested drinks. Drink order ignored.\n\n";
    }
    try {
        kOrder.addDrink("Iron Goddess"); // Kevin added another order "Iron Goddess" without knowing that the shop isn't serving this drink anymore. This should return an error message for him.
    }
    catch (InvalidInput &) {
        throw InvalidInput("Iron Goddess");
        cout << "Not serving requested drinks. Drink order ignored.\n\n";
    }

    // Now the system should print out his receipt.
    cout << setprecision(2) << fixed; // Make sure you set cout to only print out 2 decimal places.
    
    kOrder.receipt(); // We first need to call receipt() function to print out the receipt.

    // Then we output the delivery balance by calling the getTotalBalance() function.
    // The format should be similar to "Balance: $99.99\n".
    cout << "Balance: $" << kOrder.getTotalBalance() << endl;
     
    // Then we want to output the discounted balance like this "Discounted Balance: $88.88\n".
    // We get the discounted balance by having our DeliveryOrder pointer points to Kevin's order and trigger the applyDiscount() function with Kevin's account.
    //order=&kOrder;
    cout << "Discounted Balance: $" << applyDiscount(kOrder, kevin) << endl;

    //// STUART PLACING ORDER ////
    // Stuart then wants to order foods for everyone. Let's again output
    cout << "Stuart placing order." << endl;

    // Stuart creates his order with name "Stuart", same date as Kevin's order. His phone number is "123-456-1111". He's ordering from the restaurant "Tavern Green" which is 25.5 miles from their place.
    FoodOrder sOrder("Stuart", "11/20/2022", "123-456-1111", 25.5, "Tavern Green");
    // Similarly here that each of the addFood() function could cause exception, let's put all the addFood() function calls in a try catch block. Catch the InvalidInput exception by reference and trigger the print_reason() function of the exception.
    try {
        sOrder.addFood("Thick Cauliflower Steaks", 1, 1); // He's ordering a "Thick Cauliflower Steaks" with one sides and soup, a "Organic Scottish Salmon" with no side no soup
    }
    catch (InvalidInput &) {
        throw InvalidInput("Thick Cauliflower Steaks");
        cout << "Not serving requested food. Food order ignored.\n\n";
    }
    try {
        sOrder.addFood("Rack of Lamb", 0, 1); // and a "Rack of Lamb" with one soup and no side.
    }
    catch (InvalidInput &) {
        throw InvalidInput("Rack of Lamb");
        cout << "Not serving requested food. Food order ignored.\n\n";
    }
    
    sOrder.receipt(); // Now the system print out his receipt. Similarly we first call receipt() to print out the receipt for his order.
    cout << "Balance: $" << sOrder.getTotalBalance() << endl; // Then we output the delivery balance by calling getTotalBalance() function. Same format as indicated above.
    cout << "Discounted Balance: $" << applyDiscount(sOrder, stuart) << endl; // Then we output the discounted balance using the same format as above as well.
    // You would need to get the discounted balance by calling the applyDiscount() function as well.

    //// BOB PLACING ORDER ////
    // Now Bob found out that Stuart get such good pricing on food ordering, he's wondering whether he can get that too. Let's output
    cout << "Bob decided to log in to his account and see whether he can afford ordering the same order as Stuart." << endl;

    // Bob is trying to place the same order, so he's using the same order object that Stuart created. We can start by printing the receipt for Bob. We can directly call the receipt() function from the order Stuart created.
    sOrder.receipt(); 
    cout << "Balance: $" << sOrder.getTotalBalance() << endl; 
    cout << "Discounted Balance: $" << applyDiscount(sOrder, bob) << endl;
    // Then we output the delivery balance as before by calling getTotalBalance() function. Followed by printing out the discounted balance but this time we pass in Bob's account to the applyDiscount() function. Keep the same format as before when you print. Bob sees the discounted balance and he's upset that he needs to pay so much. Therefore he decided not to place the order and have Stuart do it.
    cout << "Bob is upset, cancelling order :(\n\n";
    
    // Finally, we will output the number of order placed. The format will be

    cout << "Total order placed: " << DeliveryOrder::getOrderCount() << ".\n\n";
    // You get the number of order placed by calling the static function getOrderCount() from DeliveryOrder.

    return 0;
}

//// APPLYDISCOUNT() ////
float applyDiscount(DeliveryOrder ordr, Account& acct) // take in a DeliveryOrder pointer and a constant reference account
{
    string aStatus = acct.getStatus();
    // Check the account status to determine how to apply the discount
    if (aStatus == "Owner") // Owner
    {
        return 0.1 * ordr.getOrderBalance(); // Owner get 90% off orders
    }
    else if (aStatus == "VIP") // VIP
    {
        return ordr.VIPdiscount() * ordr.getOrderBalance(); // return the order discounted based on Boba/Food order discount
    }
    else // Regular
    {
        return ordr.getOrderBalance() * 1; // no modification to order for Regular users
    }
};