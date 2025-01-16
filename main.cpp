//
// Created by David Juarez on 1/15/25.
// Runs the challenges.
//

#include <iostream>
#include "challenge01.h"

using namespace std;

int main() {
    cout << "Select a challenge to run:\n";
    cout << "1: Challenge 01\n";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Running Challenge 01" << endl;
            runChallenge01();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }

    return 0;
}