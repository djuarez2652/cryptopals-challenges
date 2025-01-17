//
// Created by David Juarez on 1/16/25.
//

#include "challenge03.h"
#include <iostream>
#include <map>
#include <string>
#include "cryptoutils.h"

using namespace std;

void runChallenge03() {
    string input = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    tuple<float, string, char> output = xor_cipher(input);

    cout << "Input: " << input << "\n" << "Decrypted: " << get<1>(output) << endl;
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



tuple<float, string, char> xor_cipher(const string &s) {
    const string bytes = hexToBytes(s);
    tuple<float, string, char> answer {-numeric_limits<float>::infinity(), "", '\0'};

    for (unsigned int i = 0; i < 256; ++i) {
        string res;
        for (const char bit : bytes) {
            const char xor_val = static_cast<char>(bit ^ i);
            if (xor_val != '\n' and !isprint(xor_val)) {
                res.erase();
                break;
            }
            res += xor_val;
        }
        if (!res.empty() && score(res) > get<0>(answer)) {
            answer = make_tuple(score(res), res, i);
        }
    }

    // cout << "Key: " << get<2>(result) << endl;
    // cout << "Value: " << get<1>(result) << endl;
    // cout << "Score: " << get<0>(result) << "\n" << endl;

    // if (get<1>(answer).empty() and get<2>(answer) == '\0') {
        // cout << "The string: " << s << " did not have a viable key" << endl;
    // }

    return answer;
}
