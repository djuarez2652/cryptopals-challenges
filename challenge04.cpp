//
// Created by David Juarez on 1/16/25.
//

#include "challenge04.h"
#include <string>
#include <fstream>
#include <iostream>
#include "challenge03.h"

using namespace std;

void DetectSingleCharXOR(const string& path);

void runChallenge04() {
    DetectSingleCharXOR("../data4.txt");
}

void DetectSingleCharXOR(const string& path) {

    ifstream inFile (path);
    if (!inFile) {
        cout << "Invalid file path" << endl;
        return;
    }

    string c;
    tuple<float, string> answer(-numeric_limits<float>::infinity(), "");
    auto i = 0;
    while (getline(inFile, c)) {
        auto currTup = xor_cipher(c);
        if (get<0>(currTup) > get<0>(answer)) {
            answer = make_tuple(get<0>(currTup), get<1>(currTup));
        }
        ++i;
    }
    cout << "Final Answer: " << get<1>(answer) << endl;
    inFile.close();
}