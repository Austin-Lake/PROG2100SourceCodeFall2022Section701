#include <iostream>
#include <exception>
#include "Rational.h"
using namespace std;

int main() {
    while(true) {
        string firstRational, secondRational;
        int numOne, numTwo;
        int denOne, denTwo;

        cout << "\nEnter integer value/values or a rational number\n" << endl;

        cout << "Enter first rational number" << endl;
        getline(cin, firstRational);

        while (!ProcessInput(firstRational, numOne, denOne)) {
            cout << "Re-enter first rational number" << endl;
            getline(cin, firstRational);
        }

        cout << "Enter second rational number" << endl;
        getline(cin, secondRational);

        while (!ProcessInput(secondRational, numTwo, denTwo)) {
            cout << "Re-enter second rational number" << endl;
            getline(cin, secondRational);
        }

        Separator();

        RationalNumber rationalOne;
        RationalNumber rationalTwo;

        PrintOperations(rationalOne, rationalTwo);

        Separator();

        RationalNumber rationalThree(numOne);
        RationalNumber rationalFour(numTwo);

        PrintOperations(rationalThree, rationalFour);

        Separator();

        RationalNumber rationalFive(numOne, denOne);
        RationalNumber rationalSix(numTwo, denTwo);

        PrintOperations(rationalFive, rationalSix);

        Separator();

        RationalNumber rationalSeven(firstRational);
        RationalNumber rationalEight(secondRational);

        PrintOperations(rationalSeven, rationalEight);

        Separator();
    }

    return 0;
}
