//
// Created by Austi on 2022-11-14.
//

#ifndef ASSIGNMENT__3_RATIONAL_H
#define ASSIGNMENT__3_RATIONAL_H
#include <iostream>
#include <string>
using namespace std;

bool ProcessInput(const string &input, int &numerator, int &denominator);

void SimplifyFraction(int &numerator, int &denominator);

int GreatestCommonFactor(const int &numerator, const int &denominator);

int LowestCommonMultiple(const int &valueOne, const int &valueTwo);

void ConvertRationalValues(int &numOne, int &denOne, int &numTwo, int &denTwo);

int CountOccurences(const string &text, const char &character);

void ReverseSign(int &value);

void Separator();


struct Fraction {
    int numerator = 0;
    int denominator = 0;
};


class RationalNumber {
private:
    int numerator;
    int denominator;

public:
    RationalNumber();
    RationalNumber(const int &num);
    RationalNumber(const int &num, const int &den);
    RationalNumber(string &fraction);

    ~RationalNumber();

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

    friend string &operator<<(string &output, RationalNumber &rationalNumber);
    friend ostream &operator<<(ostream &os, const RationalNumber &rationalNumber);
    friend ostream &operator<<(ostream &os, const Fraction &fraction);
};

void PrintOperations(RationalNumber &rationalNumberOne, RationalNumber &rationalNumberTwo);

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
