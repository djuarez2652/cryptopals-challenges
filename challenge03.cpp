//
// Created by David Juarez on 1/16/25.
//

#include "challenge03.h"
#include <iostream>
#include <map>
#include <string>

#include "cryptoutils.h"

using namespace std;

string xor_cipher(const string&);


void runChallenge03() {
    string input = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    string output = xor_cipher(input);

    cout << "Input: " << input << "\n" << "Decrypted: " << output << endl;
}

float score(string s) {
    map<char, float> weight = {
        { 'E', 11.1607 },{'A', 8.4966},
        {'R', 7.5809},{'I', 7.5448},
        {'O', 7.1635},{'T', 6.9509},
        {'N', 6.6544},{'S', 5.7351},
        {'L', 5.4893},{'C', 4.5388},
        {'U', 3.6308},{'D', 3.3844},
        {'P', .1671},
    };
    float score = 0;
    for (char c : s) {
        char upper = static_cast<char>(toupper(c));
        if (auto pos = weight.find(upper); pos != weight.end()) {
            score += weight[upper];
        }
    }

    return score;
}



string xor_cipher(const string &s) {
    const string bytes = hexToBytes(s);
    tuple<float, string, char> result {-numeric_limits<float>::infinity(), "", '\0'};

    for (unsigned int i = 0; i < 256; ++i) {
        string res;
        for (const char bit : bytes) {
            const char xor_val = static_cast<char>(bit ^ i);
            if (!isprint(xor_val)) {
                res.erase();
                break;
            }
            res += xor_val;
        }
        if (!res.empty() && score(res) > get<0>(result)) {
            result = make_tuple(score(res), res, i);
        }
    }

    // cout << "Key: " << get<2>(result) << endl;
    // cout << "Value: " << get<1>(result) << endl;
    // cout << "Score: " << get<0>(result) << "\n" << endl;

    return get<1>(result);
}
