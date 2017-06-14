/* Author: Patricia Wilthew.
 * Description: Used to implement Fraction objects
 */
using namespace std;
#include <iostream>
#include <stdio.h>
#include "Fraction.h"

int main() {

    Fraction f;
    Fraction g;

    cout << "Enter the first fraction in the form 'a / b': ";
    cin >> f;

    cout << "Enter the second fraction in the form 'a / b': ";
    cin >> g;

    cout << "Fraction 1: " << f << endl;
    cout << "Fraction 2: " << g << endl;

    cout << f << " + " << g << " = " << f+g << endl; 
    cout << f << " - " << g << " = " << f-g << endl;
    cout << f << " * " << g << " = " << f*g << endl;
    cout << "(" << f << ")" << " / " << "(" << g << ")" << " = " << f/g << endl;

    return 1;
}

