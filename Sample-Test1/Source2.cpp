#include <iostream>
#include <string>
#include "pch.h"

using namespace std;

bool isNumberString(const string& s) {
    int len = s.length();
    //if (len == 0) return false;
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

bool isValidCreditCard(const string& ccNumber) {
    if (!isNumberString(ccNumber)) {
        return false;
    }

    int len = ccNumber.length();
    int doubleEvenSum = 0;

    for (int i = len - 2; i >= 0; i = i - 2) {
        int dbl = ((ccNumber[i] - 48) * 2);
        if (dbl > 9) {
            dbl = (dbl / 10) + (dbl % 10);
        }
        doubleEvenSum += dbl;
    }

    for (int i = len - 1; i >= 0; i = i - 2) {
        doubleEvenSum += (ccNumber[i] - 48);
    }

    return (doubleEvenSum % 10 == 0);
}
