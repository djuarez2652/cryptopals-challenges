//
// Created by David Juarez on 1/15/25.
// Runs the challenges.
//

#include <iostream>
#include "challenge01.h"
#include "challenge02.h"
#include "challenge03.h"

using namespace std;

int main() {
    cout << "Select a challenge to run:\n";
    cout << "1: Challenge 01\n";
    cout << "2: Challenge 02\n";
    cout << "3: Challenge 03\n";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Running Challenge 01" << endl;
            runChallenge01();
            break;
        case 2:
            cout << "Running Challenge 02" << endl;
            runChallenge02();
            break;
        case 3:
            cout << "Running Challenge 03" << endl;
            runChallenge03();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }

    return 0;
}