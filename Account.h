#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account 
{
    //// PRIVATE ////
    private:
    // The account class will have two private attributes: username and status.
    string username;
    string status; // can be "VIP", "Owner", or "Regular".
    
    //// PUBLIC ////
    public:

    //// CONSTRUCTOR ////
    // The constructor will takes in a string to initialize the username and a string default to "Regular" to initialize the status.
    Account(string un, string st="Regular");
    // The status is optional but can be "VIP", "Owner", or "Regular".
    
    //// DESTRUCTOR ////
    // The destructor will output: "Account removed.\n"
    ~Account();

    //// SETUSERNAME() ////
    void setUsername(string name);

    //// SETSTATUS() ////
    void setStatus(string statusUpdate);

    //// GETSTATUS() ////
    // We will have one getter function getStatus to return the status of the account. Remember all non-static getter functions should be constant.
    const string getStatus();




};

#endif