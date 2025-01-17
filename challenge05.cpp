//
// Created by David Juarez on 1/16/25.
//

#include "challenge05.h"
#include <string>
#include <iostream>
#include  <iomanip>
#include <sstream>


using namespace std;

string RepeatKeyXOR(string, string);

void runChallenge05() {
    string input = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
    string key = "ICE";
    string res = RepeatKeyXOR(input, key);
    cout << "Input: " << input << "\nResult: " << res << endl;
}

string RepeatKeyXOR(string s, string key) {

    stringstream encrypted;
    unsigned int curr = 0;
    for (char c : s) {
        encrypted << setfill('0') << setw(2) << right << hex << (key[curr] ^ c);
        curr = (curr + 1) % key.length();
    }

    return encrypted.str();
}