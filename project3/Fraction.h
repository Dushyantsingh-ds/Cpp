/* Author: Patricia Wilthew.
 * Description: Definition of a Fraction Object
 */
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class Fraction {
    private:
        int numerator;
        int denominator;
        void simplify();

    public:
        Fraction();
        Fraction(int n, int d);

        void change_numerator(int newNumerator);
        void change_denominator(int newDenominator);

        Fraction operator+(const Fraction &f);
        Fraction operator-(const Fraction &f);
        Fraction operator*(const Fraction &f);
        Fraction operator/(const Fraction &f);

        friend ostream& operator<<(ostream& os, const Fraction& f);
        friend istream& operator>>(istream& is, Fraction& f);

};

#endif
