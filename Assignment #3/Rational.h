//
// Created by Austi on 2022-11-14.
//

#ifndef ASSIGNMENT__3_RATIONAL_H
#define ASSIGNMENT__3_RATIONAL_H
#include <iostream>
#include <string>
using namespace std;

// Function declarations
bool ProcessInput(const string &input, int &numerator, int &denominator);
void SimplifyFraction(int &numerator, int &denominator);
void ConvertRationalValues(int &numOne, int &denOne, int &numTwo, int &denTwo);
int GreatestCommonFactor(const int &numerator, const int &denominator);
int LowestCommonMultiple(const int &valueOne, const int &valueTwo);
int Occurence(const string &text, const char &character);
void ReverseSign(int &value);
void Separator();

// Struct to store the values of the overloaded mathematical operators
struct Fraction {
    int numerator = 0;
    int denominator = 0;
};

// Rational Number class
class RationalNumber {
private:
    int numerator;
    int denominator;

public:
    // Default and overloaded constructor declarations
    RationalNumber();
    RationalNumber(const int &num);
    RationalNumber(const int &num, const int &den);
    RationalNumber(string &fraction);
    // Deconstructor declaration
    ~RationalNumber();

    // Overloaded equality operators

    bool operator==(const RationalNumber &rationalNumber) const {
        cout << "   Equal Operator Fired!" << endl;

        int a = numerator;
        int b = denominator;
        int c = rationalNumber.numerator;
        int d = rationalNumber.denominator;

        if(b != d) {
            ConvertRationalValues(a, b, c, d);
        }

        return a == c;
    }
    bool operator<(const RationalNumber &rationalNumber) const {
        cout << "   Less than Operator Fired!" << endl;

        int a = numerator;
        int b = denominator;
        int c = rationalNumber.numerator;
        int d = rationalNumber.denominator;

        if(b != d) {
            ConvertRationalValues(a, b, c, d);
        }

        return a < c;
    }
    bool operator>(const RationalNumber &rationalNumber) const {
        cout << "   Greater than Operator Fired!" << endl;

        int a = numerator;
        int b = denominator;
        int c = rationalNumber.numerator;
        int d = rationalNumber.denominator;

        if(b != d) {
            ConvertRationalValues(a, b, c, d);
        }

        return a > c;
    }

    // Overloaded mathematical operators

    Fraction &operator/(const RationalNumber &rationalNumber) const {
        cout << "    Division Operator Fired!" << endl;

        static Fraction fraction;
        int a = numerator;
        int b = denominator;
        int c = rationalNumber.numerator;
        int d = rationalNumber.denominator;

        if(b != d) {
            ConvertRationalValues(a, b, c, d);
        }

        a *= d, b *= c;
        SimplifyFraction(a, b);
        fraction.numerator = a, fraction.denominator = b;

        return fraction;
    }
    Fraction &operator*(const RationalNumber &rationalNumber) const {
        cout << "    Multiplication Operator Fired!" << endl;

        static Fraction fraction;
        int a = numerator;
        int b = denominator;
        int c = rationalNumber.numerator;
        int d = rationalNumber.denominator;

        a *= c, b *= d;
        SimplifyFraction(a, b);
        fraction.numerator = a, fraction.denominator = b;

        return fraction;
    }
    Fraction &operator+(const RationalNumber &rationalNumber) const {
        cout << "    Addition Operator Fired!" << endl;

        static Fraction fraction;
        int a = numerator;
        int b = denominator;
        int c = rationalNumber.numerator;
        int d = rationalNumber.denominator;

        if(b != d) {
            ConvertRationalValues(a, b, c, d);
        }

        a += c;
        SimplifyFraction(a, b);
        fraction.numerator = a, fraction.denominator = b;

        return fraction;
    }
    Fraction &operator-(const RationalNumber &rationalNumber) const {
        cout << "    Subtraction Operator Fired!" << endl;

        static Fraction fraction;
        int a = numerator;
        int b = denominator;
        int c = rationalNumber.numerator;
        int d = rationalNumber.denominator;

        if(b != d) {
            ConvertRationalValues(a, b, c, d);
        }

        a -= c;
        SimplifyFraction(a, b);
        fraction.numerator = a, fraction.denominator = b;

        return fraction;
    }

    // Friend declarations of overloaded output operator
    friend string &operator<<(string &output, RationalNumber &rationalNumber);
    friend ostream &operator<<(ostream &os, const RationalNumber &rationalNumber);
    friend ostream &operator<<(ostream &os, const Fraction &fraction);
};
// Print function declared after class declaration inorder to pass in class objects as parameters
void PrintOperations(RationalNumber &rationalNumberOne, RationalNumber &rationalNumberTwo);

// Inline Implementations of overloaded output operator

inline string &operator<<(string &output, RationalNumber &rationalNumber) {
    output += to_string(rationalNumber.numerator) + "/" + to_string(rationalNumber.denominator);

    return output;
}
inline ostream &operator<<(ostream &os, const RationalNumber &rationalNumber) {
    os << rationalNumber.numerator << "/" << rationalNumber.denominator;

    return os;
}
inline ostream &operator<<(ostream &os, const Fraction &fraction) {
    os << fraction.numerator << "/" << fraction.denominator;

    return os;
}

#endif //ASSIGNMENT__3_RATIONAL_H
