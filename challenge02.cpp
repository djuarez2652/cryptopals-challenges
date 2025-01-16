//
// Created by David Juarez on 1/16/25.
// https://cryptopals.com/sets/1/challenges/2
//

#include <string>
#include <iostream>
#include <sstream>
#include "cryptoutils.h"


using namespace std;

string fixed_xor(string, string);

void runChallenge02() {
    string input1 = "1c0111001f010100061a024b53535009181c";
    string input2 = "686974207468652062756c6c277320657965";
    string xor_value = fixed_xor(input1, input2);
    cout << "value of " << input1 << " XOR " << input2 << " is " << xor_value << endl;
}

string fixed_xor(string s1, string s2) {

    stringstream xorStream;

    int max_length = static_cast<int>(max(s1.length(), s2.length()));
    string pad_s1 = padLeft(s1, max_length, '0');
    string pad_s2 = padLeft(s2, max_length, '0');

    // cout << "processing " << pad_s1 << " and " << pad_s2 << endl;


    for (auto i = 0; i < max_length; i += 2) {
        unsigned int s1_hex = charToHex(pad_s1[i]) << 4 | charToHex(pad_s1[i+1]) & 15;
        unsigned int s2_hex = charToHex(pad_s2[i]) << 4 | charToHex(pad_s2[i+1]) & 15;

        xorStream << hex << (s1_hex ^ s2_hex);
    }

    return xorStream.str();
}
