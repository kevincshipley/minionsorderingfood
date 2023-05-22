#include "Account.h" // Account.h
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//// CONSTRUCTOR ////
Account::Account(string un, string st) {
    // The status is optional but can be "VIP", "Owner", or "Regular".
    setUsername(un);
    setStatus(st);
};

//// DESTRUCTOR ////
Account::~Account() {
    cout << "Account removed.\n";
};

//// SETUSERNAME() ////
void Account::setUsername(string name) {
    Account::username = name;
}
//// SETSTATUS() ////
void Account::setStatus(string statusUpdate) {
    Account::status = statusUpdate;
}

//// GETSTATUS() ////
const string Account::getStatus() // return the status of the account.
{
    return status;
};
