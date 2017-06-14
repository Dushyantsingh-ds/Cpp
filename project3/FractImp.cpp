/* Author: Patricia Wilthew.
 * Description: Implementation file for the Fraction Object
 */
#include "Fraction.h"
#include <iostream>
using namespace std;

/*
 * Default constructor
 */
Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

/*
 * 2 parameters constructor
 */
Fraction::Fraction(int n, int d) {
    numerator = n;
    denominator = d;
}

/*
 * Mutator: Sets or changes the numerator member of a Fraction object
 */
void Fraction::change_numerator(int newNumerator) {

 	numerator = newNumerator;

}

/*
 * Mutator: Sets or changes the denominator member of a Fraction object
 */
void Fraction::change_denominator(int newDenominator) {

    denominator = newDenominator;

}

/*
 * Operator function for +
 */
Fraction Fraction::operator+(const Fraction &f) {

	Fraction newFraction;

	newFraction.numerator = (f.denominator * this->numerator) + (this->denominator * f.numerator);
    newFraction.denominator = (f.denominator * this->denominator);

    newFraction.simplify();

    return newFraction;
}

/*
 * Operator function for -
 */
Fraction Fraction::operator-(const Fraction &f) {

	Fraction newFraction;

    newFraction.numerator = (f.denominator * this->numerator) - (this->denominator * f.numerator);
	newFraction.denominator = (f.denominator * this->denominator);

    newFraction.simplify();

    return newFraction;
}

/*
 * Operator function for *
 */
Fraction Fraction::operator*(const Fraction &f) {

	Fraction newFraction;

    newFraction.numerator = (f.numerator * this->numerator);
    newFraction.denominator = (f.denominator * this->denominator);

    newFraction.simplify();

    return newFraction;
}

/*
 * Operator function for /
 */
Fraction Fraction::operator/(const Fraction &f) {

    Fraction newFraction;

    newFraction.numerator = (this->numerator * f.denominator);
    newFraction.denominator = (f.numerator * this->denominator);

    newFraction.simplify();

    return newFraction;
}

/*
 * Operator function for <<
 */
ostream& operator<<(ostream& os, const Fraction& f) {

	os << f.numerator << " / " << f.denominator;

    return os;

}

/*
 * Operator function for >>
 */
istream& operator>>(istream& is, Fraction& f) {

	char ch;

    is >> f.numerator;
    is >> ch;
    is >> f.denominator;

    return is;
}

/*
 * Fraction simplify function
 */
void Fraction::simplify() {
    
    int i = numerator*denominator;

    for (; i > 1; i--) { 
        
        if ((numerator%i == 0) && (denominator%i == 0)) {
            numerator = numerator / i;
            denominator = denominator / i;
        }
    }

}
