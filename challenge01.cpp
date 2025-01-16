//
// Created by David Juarez on 1/16/25.
// https://cryptopals.com/sets/1/challenges/1
//

#include <iostream>
#include <string>
#include <sstream>
#include "cryptoutils.h"

using namespace std;

string sHexToBase64(string);

const string BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void runChallenge01() {
    string input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    string output = sHexToBase64(input);
    cout << "Hex input: " << input << "\n" << "Base64: " << output << endl;
}

string sHexToBase64(string s) {
    if (s.length() % 2 != 0)
        throw new invalid_argument("Hex string must have an even length.");

    bool useFirst = true;
    size_t n = s.length();
    stringstream base64Stream;

    for (auto i = 0; i < n; ++i) {
        unsigned int first = charToHex(s[i]);
        unsigned int second = charToHex(s[i+1]);

        if (useFirst) {
            first <<= 2;
            second = (second & 12) >> 2;
        } else {
            first = (first & 3) << 4;
            second &= 15;
            ++i;
        }

        base64Stream << BASE64_CHARS[first | second];
        useFirst = !useFirst;
    }

    return base64Stream.str();
}
