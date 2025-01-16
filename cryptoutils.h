//
// Created by David Juarez on 1/16/25.
//

#ifndef CRYPTOUTILS_H
#define CRYPTOUTILS_H

#include <string>

unsigned int charToHex(char c);
std::string padLeft(std::string s, int desiredLength, char padding);
int hexToInt(char hex);
std::string hexToBytes(std::string hex);


#endif //CRYPTOUTILS_H
