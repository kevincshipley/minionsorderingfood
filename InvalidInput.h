#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

class InvalidInput {
    public:
        //// CONSTRUCTOR ////
        InvalidInput(string input) : message("Invalid input \"" + input + "\".\n") {
            print_reason();
        };

        //// PRINT_REASON() ////
        void print_reason() {
            cout << message;
        };

    private:
        const string message;
};

#endif