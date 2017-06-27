/* Author: Patricia Wilthew.
 * Description: This program demonstrates a base class and a derived class
 */
#include <iostream>
#include <iomanip>
#include "Essay.h"
using namespace std;

int main()
{   
    int grammar, spelling, length, content;

    cout << "How many grammar points did the student earn? (0 - 30): ";
    cin >> grammar;
    while (grammar < 0 || grammar > 30) 
    {
        cout << "Invalid. Enter a number from 0 through 30: ";
        cin >> grammar;
    }

    cout << "How many spelling points did the student earn? (0 - 20): ";
    cin >> spelling;
    while (spelling < 0 || spelling > 20) 
    {
        cout << "Invalid. Enter a number from 0 through 20: ";
        cin >> spelling;
    }

    cout << "How many points for length did the student earn? (0 - 20): ";
    cin >> length;
    while (length < 0 || length > 20) 
    {
        cout << "Invalid. Enter a number from 0 through 20: ";
        cin >> length;
    }

    cout << "How many points for content did the student earn? (0 - 30): ";
    cin >> content;
    while (content < 0 || content > 30) 
    {
        cout << "Invalid. Enter a number from 0 through 30: ";
        cin >> content;
    }

    Essay p(grammar, spelling, length, content);

    cout << "Grammar points: " << p.getGrammarPoints() << endl;
    cout << "Spelling points: " << p.getSpellingPoints() << endl;
    cout << "Length points: " << p.getCorrectLengthPoints() << endl;
    cout << "Content points: " << p.getContentPoints() << endl;
    cout << "Overal score: " << p.getScore() << endl;
    cout << "Grade: " << p.getLetterGrade() << endl;
    return 0;
}
