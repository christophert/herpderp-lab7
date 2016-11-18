#ifndef GETINPUT
#define GETINPUT

#include <string>

using namespace std;

int getInput(const string &purpose, int (*verifyFunction)(string), string &retvar);

#endif
