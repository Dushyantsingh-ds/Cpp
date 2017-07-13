 /* Author: Patricia Wilthew.
  * Description: Driver program
  */
#include "FeetInches.h"
#include <iostream>
#include <string>
using namespace std;

template <class T> T maximum(T,T);
template <class T> T minimum(T,T);

int main() {

	int a, b;
	double c, d;
	string e, f;
	FeetInches g, h;

	// Comparing integers
	cout << "Enter two integers separated by a space character: ";
	cin >> a >> b;
	cout << "The maximum is " << maximum(a,b) << endl << "The minimum is " << minimum(a,b) << endl;

	// Comparing doubles
	cout << "Enter two floating point numbers separated by a space character: ";
	cin >> c >> d;
	cout << "The maximum is " << maximum(c,d) << endl << "The minimum is " << minimum(c,d) << endl;

	// Comparing strings
	cout << "Enter one string: ";
	cin >> e;
	cout << "Enter another string: ";
	cin >> f;
	cout << "The maximum is " << maximum(e,f) << endl << "The minimum is " << minimum(e,f) << endl;

	// Comparing FeetInches
	cout << "Enter the first distance () in 'feet, inches' format: ";
	cin >> g;
	cout << "Enter the second distance () in 'feet, inches' format: ";
	cin >> h;
	cout << "The maximum is " << maximum(g,h) << endl << "The minimum is " << minimum(g,h) << endl;

	return 0;
}

template <class T> T maximum(T a, T b) {
	
	return (a > b) ? a : b;

}

template <class T> T minimum(T a, T b) {
	
	return (a < b) ? a : b;
}
