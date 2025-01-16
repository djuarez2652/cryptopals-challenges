//
// Created by David Juarez on 1/16/25.
//

#include "cryptoutils.h"
#include <locale>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <string>


using namespace std;

unsigned int charToHex(const char c) {
    unsigned int hex;
    if (isdigit(c)) {
        hex = c - '0';
    } else {
        hex = (tolower(c, locale())) - 'a' + 10;
    }
    return hex;
}

string padLeft(string s, const int desiredLength, const char padding=' ') {

    if (s.length() >= desiredLength)
        return s;

    stringstream paddedStream;
    const int padAmount = abs(static_cast<int>(s.length()) - desiredLength);

    paddedStream << setfill(padding) << setw(desiredLength) << right << s;

    return paddedStream.str();
}

int hexToInt(char hex) {

    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    } else {
        throw std::invalid_argument("Invalid hex character");
    }
}