//
// Created by Austi on 2022-11-14.
//

#include "Rational.h"
#include <iostream>
#include <string>
using namespace std;

int rationalNum = 0;

// Implementations of default and overloaded constructors and destructor

// Default Constructor
RationalNumber::RationalNumber() {
    cout << "Default Constructor Fired!" << endl;
    rationalNum++;

    numerator = 0, denominator = 1;

    cout << "   Rational Number Object " << rationalNum << " created with a value of '"
    << numerator << '/' << denominator << "'\n" << endl;
}
// One Argument Constructor
RationalNumber::RationalNumber(const int &num) {
    cout << "One Argument Constructor Fired!" << endl;
    rationalNum++;

    numerator = num, denominator = 1;

    cout << "   Rational Number Object " << rationalNum << " created with a value of '"
    << numerator << '/' << denominator << "'\n" << endl;

    SimplifyFraction(numerator, denominator);
}
// Two Argument Constructor
RationalNumber::RationalNumber(const int &num, const int &den) {
    cout << "Two Argument Constructor Fired!" << endl;
    rationalNum++;

    numerator = num, denominator = den;

    cout << "   Rational Number Object " << rationalNum << " created with a value of '"
    << numerator << '/' << denominator << "'\n" << endl;

    SimplifyFraction(numerator, denominator);
}
// String Constructor
RationalNumber::RationalNumber(string &rationalNumber) {
    cout << "String Constructor Fired!" << endl;
    rationalNum++;

    ProcessInput(rationalNumber, numerator, denominator);

    cout << "   Rational Number Object " << rationalNum << " created with a value of '"
    << numerator << '/' << denominator << "'\n" << endl;

    SimplifyFraction(numerator, denominator);
}
// Deconstructor
RationalNumber::~RationalNumber() {
    cout << "Deconstructor Fired! on Object: " << rationalNum << endl;
    rationalNum--;
}

// Function Implementations

// Print function to output the results of the overloaded operators for each set of objects
void PrintOperations(RationalNumber &rationalOne, RationalNumber &rationalTwo) {
    // String value to store and print a message after all comparison operators have fired
    string message;
    // Struct values to store the results of each overloaded mathematical operator
    Fraction addedFraction, subtractedFraction, multipliedFraction, dividedFraction;

    // Executes each overloaded comparison operator and stores output into message
    if(rationalOne == rationalTwo)
        message = "         Object ",
        message += to_string(rationalNum-1),
        message += ": '",
        message << rationalOne += "' is equal to Object ",
        message += to_string(rationalNum),
        message += ": '",
        message << rationalTwo += "'\n";
    if(rationalOne < rationalTwo)
        message = "         Object ",
        message += to_string(rationalNum-1),
        message += ": '",
        message << rationalOne += "' is less than Object ",
        message += to_string(rationalNum),
        message += ": '",
        message << rationalTwo += "'\n";
    if(rationalOne > rationalTwo)
        message = "         Object ",
        message += to_string(rationalNum-1),
        message += ": '",
        message << rationalOne += "' is greater than Object ",
        message += to_string(rationalNum),
        message += ": '",
        message << rationalTwo += "'\n";

    // Prints message to console
    cout << message << endl;

    // Uses each overloaded mathematical operator storing the result inside their respective
    // struct value and uses the overloaded output operator to write structs to the output stream
    addedFraction = rationalOne + rationalTwo;
    cout << "         Object " << to_string(rationalNum-1)
        << " plus Object " << to_string(rationalNum) << " = " << addedFraction << endl;
    subtractedFraction = rationalOne - rationalTwo;
    cout << "         Object " << to_string(rationalNum-1)
        << " subtract Object " << to_string(rationalNum) << " = " << subtractedFraction << endl;
    multipliedFraction = rationalOne * rationalTwo;
    cout << "         Object " << to_string(rationalNum-1)
         << " multiplied by Object " << to_string(rationalNum) << " = " << multipliedFraction << endl;
    dividedFraction = rationalOne / rationalTwo;
    cout << "         Object " << to_string(rationalNum-1)
         << " divided by Object " << to_string(rationalNum) << " = " << dividedFraction << endl;
}

bool ProcessInput(const string &input, int &numerator, int &denominator) {
    // Default values to store the numerator and denominator
    string valOne = "0", valTwo = "1";
    // size_t variable to store position of special character in string
    size_t pos = -1;

    // Check to see if space or backslash character occur more than once
    if(Occurence(input, ' ') > 1 || Occurence(input, '/') > 1) {
        cout << "Input contains too many values" << endl;
        return false;
    }

    // Gets the position of either the space character or backslash character and
    // sets the values to the sub strings on either side of that character
    // if no valid character is found it assigns the whole string to the first value
    if((pos = input.find_first_of(' ')) != string::npos || (pos = input.find_first_of('/')) != string::npos) {
        valOne = input.substr(0, pos);
        valTwo = input.substr(pos+1);
    }
    else {
        valOne = input;
    }

    // Checks the first and second values for decimals
    if(valOne.find('.') != string::npos || valTwo.find('.') != string::npos) {
        cout << "Value can't contain decimals." << endl;
        return false;
    }

    // Attempts to parse string values into the numerator and denominator values passed in as references
    try {
        numerator = stoi(valOne), denominator = stoi(valTwo);

        // Checks to see if denominator value is zero
        if(denominator == 0) {
            cout << "Denominator value can't be zero" << endl;
            return false;
        }
    }
    catch(invalid_argument) {
        cout << "String value is not valid." << endl;
        return false;
    }
    catch(out_of_range) {
        cout << "Numerical value is too large." << endl;
        return false;
    }

    return true;
}
// Function to simplify numerator and denominator values passed in
void SimplifyFraction(int &numerator, int &denominator) {
    // Gets the Greatest Common Factor of numerator and denominator
    int GCF = GreatestCommonFactor(numerator, denominator);

    // Early return if Greatest Common Factor is zero
    if (GCF == 0)
        return;

    // If denominator is less than zero it reverses
    // the sign of both the denominator and numerator
    if(denominator < 0)
        ReverseSign(numerator), ReverseSign(denominator);

    // Divides both values by the Greatest Common Factor
    // to get their simplified versions
    numerator /= GCF, denominator /= GCF;
}

// Convert values function to make denominators equal
void ConvertRationalValues(int &numOne, int &denOne, int &numTwo, int &denTwo) {
    // Gets the Lowest Common Multiple of both denominators
    int LCM = LowestCommonMultiple(denOne, denTwo);

    // Early Return if Lowest Common Multiple equals zero
    if (LCM == 0)
        return;

    // Creates a factor based on the Lowest Common Multiple divided by each denominator
    int FirstFactor = LCM / denOne, SecondFactor = LCM / denTwo;

    // Multiplies each numerator and denominator value by their respective factor
    numOne *= FirstFactor, denOne *= FirstFactor;
    numTwo *= SecondFactor, denTwo *= SecondFactor;
}

// Function to get the Greatest Common Factor of two values
int GreatestCommonFactor(const int &valueOne, const int &valueTwo) {
    // Returns zero if either value is zero
    if (valueOne == 0 || valueTwo == 0)
        return 0;

    // Temporary variables to store each value
    int valOne = valueOne, valTwo = valueTwo;

    // Reverses each temporary value if they are negative
    if(valueOne < 0)
        ReverseSign(valOne);
    if(valueTwo < 0)
        ReverseSign(valTwo);

    // Keeps subtracting the smaller value from the larger until both are equal
    while(valOne != valTwo) {
        if(valOne > valTwo)
            valOne -= valTwo;
        else
            valTwo -= valOne;
    }

    // Returns the Greatest Common Factor value
    return valOne;
}

// Function to get the Lowest Common Multiple
int LowestCommonMultiple(const int &valueOne, const int &valueTwo) {
    // Returns zero if either value is zero
    if (valueOne == 0 || valueTwo == 0)
        return 0;

    // Temporary variables to store each value
    int valOne = valueOne, valTwo = valueTwo;

    // Reverses each temporary value if they are negative
    if(valueOne < 0)
        ReverseSign(valOne);
    if(valueTwo < 0)
        ReverseSign(valTwo);

    // Keeps adding the original value to the smaller
    // temporary value until both temporary values are equal
    while(valOne != valTwo) {
        if(valOne < valTwo)
            valOne += valueOne;
        else
            valTwo += valueTwo;
    }

    // Returns the Lowest Common Multiple value
    return valOne;
}

// Function to count the number of occurences a character is found in a string
int Occurence(const string &text, const char &character) {
    // Variable to store the count
    int count = 0;

    // Ranged based for loop to iterate through each
    // character in a string and increments the counter if
    // the character is equal to the one passed in
    for(char i : text) {
        if(i == character)
            count++;
    }

    // Returns counter
    return count;
}

// Function to reverse the value passed in by multiplying by negative 1
void ReverseSign(int &value) {
    value *= -1;
}

// Function to create a separator between sections of text
void Separator() {
    cout << "\n-----------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------------------------\n" << endl;
}