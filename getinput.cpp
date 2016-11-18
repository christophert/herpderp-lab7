#include <iostream>
#include "getinput.h"

int getInput(const string &purpose, int (*verifyFunction)(string), string &retvar) {
    string inputvar = "";
    cout << "Please enter " + purpose + ": ";
    getline(cin, inputvar);

    if(verifyFunction(inputvar)) {
        retvar = inputvar;
        return true;
    }
    else {
        cout << "Input for " + purpose + " invalid" << endl;
        return false;
    }
}
