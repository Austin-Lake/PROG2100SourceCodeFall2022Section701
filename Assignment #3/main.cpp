#include <iostream>
#include <exception>
#include "Rational.h"
using namespace std;

int main() {
    // Infinite Loop
    while(true) {
        // Variables to store each rational number string and their extracted integer values
        string firstRational, secondRational;
        int numOne, numTwo;
        int denOne, denTwo;

        cout << "\nEnter integer value/values or a rational number\n" << endl;

        // Asks for first rational number
        cout << "Enter first rational number" << endl;
        getline(cin, firstRational);

        // Keeps asking for first rational value if it's not valid
        while (!ProcessInput(firstRational, numOne, denOne)) {
            cout << "Re-enter first rational number" << endl;
            getline(cin, firstRational);
        }

        // Asks for second rational number
        cout << "Enter second rational number" << endl;
        getline(cin, secondRational);

        // Keeps asking for second rational value if it's not valid
        while (!ProcessInput(secondRational, numTwo, denTwo)) {
            cout << "Re-enter second rational number" << endl;
            getline(cin, secondRational);
        }

        Separator();

        // Instantiation of default constructor for rational number objects 1 & 2
        RationalNumber rationalOne;
        RationalNumber rationalTwo;

        // Print the output for all overloaded operators pertaining to objects 1 & 2
        PrintOperations(rationalOne, rationalTwo);

        Separator();

        // Instantiation of one argument constructor for rational number objects 3 & 4
        RationalNumber rationalThree(numOne);
        RationalNumber rationalFour(numTwo);

        // Print the output for all overloaded operators pertaining to objects 3 & 4
        PrintOperations(rationalThree, rationalFour);

        Separator();

        // Instantiation of two argument constructor for rational number objects 5 & 6
        RationalNumber rationalFive(numOne, denOne);
        RationalNumber rationalSix(numTwo, denTwo);

        // Print the output for all overloaded operators pertaining to objects 5 & 6
        PrintOperations(rationalFive, rationalSix);

        Separator();

        // Instantiation of string constructor for rational number objects 7 & 8
        RationalNumber rationalSeven(firstRational);
        RationalNumber rationalEight(secondRational);

        // Print the output for all overloaded operators pertaining to objects 7 & 8
        PrintOperations(rationalSeven, rationalEight);

        Separator();

        // Loop ends, calls deconstructors, and reiterates
    }

    return 0;
}
