//
// Created by Austi on 2022-11-14.
//

#include "Rational.h"
#include <iostream>
#include <string>
using namespace std;

int rationalNum = 0;


RationalNumber::RationalNumber() {
    cout << "Default Constructor Fired!" << endl;
    rationalNum++;

    numerator = 0, denominator = 1;

    cout << "   Rational Number " << rationalNum << " created with a value of '"
    << numerator << '/' << denominator << "'\n" << endl;
}
RationalNumber::RationalNumber(const int &num) {
    cout << "One Argument Constructor Fired!" << endl;
    rationalNum++;

    numerator = num, denominator = 1;

    cout << "   Rational Number " << rationalNum << " created with a value of '"
    << numerator << '/' << denominator << "'\n" << endl;

    SimplifyFraction(numerator, denominator);
}
RationalNumber::RationalNumber(const int &num, const int &den) {
    cout << "Two Argument Constructor Fired!" << endl;
    rationalNum++;

    numerator = num, denominator = den;

    cout << "   Rational Number " << rationalNum << " created with a value of '"
    << numerator << '/' << denominator << "'\n" << endl;

    SimplifyFraction(numerator, denominator);
}
RationalNumber::RationalNumber(string &rationalNumber) {
    cout << "String Constructor Fired!" << endl;
    rationalNum++;

    ProcessInput(rationalNumber, numerator, denominator);

    cout << "   Rational Number " << rationalNum << " created with a value of '"
    << numerator << '/' << denominator << "'\n" << endl;

    SimplifyFraction(numerator, denominator);
}

RationalNumber::~RationalNumber() {
    cout << "Deconstructor Fired! on Rational Number: " << rationalNum << endl;
    rationalNum--;
}

void SimplifyFraction(int &numerator, int &denominator) {
    if (numerator == 0)
        return;

    int GCF = GreatestCommonFactor(numerator, denominator);

    if(denominator < 0)
        ReverseSign(numerator), ReverseSign(denominator);

    numerator /= GCF, denominator /= GCF;
}

int GreatestCommonFactor(const int &numerator, const int &denominator) {
    if (numerator == 0)
        return 0;

    int num = numerator, den = denominator;

    if(numerator < 0)
        ReverseSign(num);
    if(denominator < 0)
        ReverseSign(den);

    while(num != den) {
        if(num > den)
            num -= den;
        else
            den -= num;
    }

    return num;
}

void ConvertRationalValues(int &numOne, int &denOne, int &numTwo, int &denTwo) {
    int LCM = LowestCommonMultiple(denOne, denTwo);
    int FirstFactor = LCM / denOne, SecondFactor = LCM / denTwo;

    numOne *= FirstFactor, denOne *= FirstFactor;
    numTwo *= SecondFactor, denTwo *= SecondFactor;
}

int LowestCommonMultiple(const int &valueOne, const int &valueTwo) {
    if (valueOne == 0 || valueTwo == 0)
        return 0;

    int valOne = valueOne, valTwo = valueTwo;

    if(valueOne < 0)
        ReverseSign(valOne);
    if(valueTwo < 0)
        ReverseSign(valTwo);

    while(valOne != valTwo) {
        if(valOne < valTwo)
            valOne += valueOne;
        else
            valTwo += valueTwo;
    }

    return valOne;
}

bool ProcessInput(const string &input, int &numerator, int &denominator) {
    string valOne = "0", valTwo = "1";
    size_t pos = -1;

    if(CountOccurences(input, ' ') > 1 || CountOccurences(input, '/') > 1) {
        cout << "Input contains too many values" << endl;
        return false;
    }

    if((pos = input.find_first_of(' ')) != string::npos || (pos = input.find_first_of('/')) != string::npos) {
        valOne = input.substr(0, pos);
        valTwo = input.substr(pos+1);
    }
    else {
        valOne = input;
    }

    if(valOne.find('.') != string::npos || valTwo.find('.') != string::npos) {
        cout << "Value can't contain decimals." << endl;
        return false;
    }

    try {
        numerator = stoi(valOne), denominator = stoi(valTwo);

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

int CountOccurences(const string &text, const char &character) {
    int num = 0;

    for(char i : text) {
        if(i == character)
            num++;
    }

    return num;
}

void ReverseSign(int &value) {
    value *= -1;
}

void PrintOperations(RationalNumber &rationalOne, RationalNumber &rationalTwo) {
    string message;
    Fraction addedFraction, subtractedFraction, multipliedFraction, dividedFraction;

    if(rationalOne == rationalTwo)
        message = "         Rational Number ",
        message += to_string(rationalNum-1),
        message += ": '",
        message << rationalOne += "' is equal to Rational Number ",
        message += to_string(rationalNum),
        message += ": '",
        message << rationalTwo += "'\n";
    if(rationalOne < rationalTwo)
        message = "         Rational Number ",
        message += to_string(rationalNum-1),
        message += ": '",
        message << rationalOne += "' is less than Rational Number ",
        message += to_string(rationalNum),
        message += ": '",
        message << rationalTwo += "'\n";
    if(rationalOne > rationalTwo)
        message = "         Rational Number ",
        message += to_string(rationalNum-1),
        message += ": '",
        message << rationalOne += "' is greater than Rational Number ",
        message += to_string(rationalNum),
        message += ": '",
        message << rationalTwo += "'\n";

    cout << message << endl;

    addedFraction = rationalOne + rationalTwo;
    cout << "         Rational Number " << to_string(rationalNum-1)
    << " plus Rational Number " << to_string(rationalNum) << " = " << addedFraction << endl;
    subtractedFraction = rationalOne - rationalTwo;
    cout << "         Rational Number " << to_string(rationalNum-1)
    << " subtract Rational Number " << to_string(rationalNum) << " = " << subtractedFraction << endl;
    multipliedFraction = rationalOne * rationalTwo;
    cout << "         Rational Number " << to_string(rationalNum-1)
    << " multiplied by Rational Number " << to_string(rationalNum) << " = " << multipliedFraction << endl;
    dividedFraction = rationalOne / rationalTwo;
    cout << "         Rational Number " << to_string(rationalNum-1)
    << " divided by Rational Number " << to_string(rationalNum) << " = " << dividedFraction << endl;
}

void Separator() {
    cout << "\n-----------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------------------------\n" << endl;
}