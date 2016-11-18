#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <regex>
#include "verify.h"

int verifyDate(string datestr) {
    if(datestr.length() != 10)
        return false;

    int month, day, year;
    if(sscanf(datestr.c_str(), "%2d/%2d/%4d", &month, &day, &year) != 3)
        return false;

    if(
        ((month < 1 || month > 12) ||
        (day < 1 || day > 31) ||
        (year < 1900)) 
    ) {
        return false;
    }


    //normalize
    struct tm t = {0};
    t.tm_mon = month - 1;
    t.tm_mday = day;
    t.tm_year = year - 1900;
    t.tm_isdst = -1;

    time_t when = mktime(&t);
    const struct tm *norm = localtime(&when);

    // check if normalized date is still the same
    return (norm->tm_mon == month-1 &&
            norm->tm_mday == day &&
            norm->tm_year == year - 1900);
}

int verifyCC(string ccno) {
    if(ccno.length() != 19)
        return false;

    int s1, s2, s3, s4;
    return sscanf(ccno.c_str(), "%4d-%4d-%4d-%4d", &s1, &s2, &s3, &s4) == 4;
}

int verifyZIP(string zip) {
    if(zip.length() != 5 && zip.length() != 10)
        return false;

    int izip, plus4;
    if(zip.length() == 5) {
        return sscanf(zip.c_str(), "%5d", &izip) == 1;
    } else if (zip.length() == 10) {
        return sscanf(zip.c_str(), "%5d-%4d", &izip, &plus4) == 2;
    } else {
        return false;
    }
}

int verifyPurchAmt(string purchamt) {
    int major, minor;
    return sscanf(purchamt.c_str(), "%d.%2d", &major, &minor) == 2;
}

int verifyEmail(string email) {
    const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    return std::regex_match(email, pattern);
}
