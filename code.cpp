#include <iostream>
#include "verify.h"
#include "getinput.h"

using namespace std;

const string monthName[] = {
    "January",
    "Feburary",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

int convertDate(string datestr, string &result);

int main() {

    string firstname = "";
    string lastname = "";
    string ccno = "";
    string expr = "";
    string expr_result = "";
    string zip = "";
    string purchamt = "";
    string email = "";
    
    cout << "Please enter first name: ";
    getline(cin, firstname);

    cout << "Please enter last name: ";
    getline(cin, lastname);

    if(!getInput("credit card number", verifyCC, ccno)) return false;

    if(!getInput("expiration date", verifyDate, expr)) return false;
    convertDate(expr, expr_result);
    if(!getInput("ZIP Code", verifyZIP, zip)) return false;


    if(!getInput("Purchase Amount", verifyPurchAmt, purchamt)) return false;

    if(!getInput("Email", verifyEmail, email)) return false;

    cout << "Name: \t\t\t\t" << firstname << " " << lastname << endl;
    cout << "Credit Card Number: \t\t" << ccno << endl;
    cout << "Expiration month and year: \t" << expr_result << endl;
    cout << "Zip Code: \t\t\t" << zip << endl;
    cout << "Purchase amount: \t\t" << purchamt << endl;
    cout << "Email Address: \t\t\t" << email << endl;
}


int convertDate(string datestr, string& result) {
    int month, day, year;
    if(sscanf(datestr.c_str(), "%2d/%2d/%4d", &month, &day, &year) != 3)
        return false;

    int index = month - 1;
    result = monthName[index]+ " "+ std::to_string(day);
    return true;
}

