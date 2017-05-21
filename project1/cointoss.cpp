/* Author: Patricia Wilthew.
 * Description: Given a number n through standard input, the program will simulate
 *  the "tossing" of a coin n times. Afterwards, it will determine if the proportion
 *  of head vs. tails was realistic or not.
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int flip();
int valid(int, int);

int main() {

    int n;
    int i;
    int random; 
    int tails = 0;
    int heads = 0;
    int count = 0;

    cout << "Enter the number of times you want to toss the coin: ";
    cin >> n;

	// Input validation
	while (n < 10) {
        cout << "The number of tosses must be greater than 10. Reenter: ";
        cin >> n;
    }

	// Seed for random
    srand(time(NULL));
 
 	// Tossing process
    for (i = 0; i < n; i++) { 

        random = flip();

        if (random == 1) {
            cout << "Tails\t";
            tails += 1;
        } else {
            cout << "Heads\t";
            heads += 1;
        }

        count += 1;

        if (count == 10) {
            count = 0;
            cout << endl;
        }
    }

    cout << endl;
    cout << "The total number of heads was " << heads << endl;
    cout << "The total number of tails was " << tails << endl;

    if (valid(heads, tails)==1)
        cout << "This simulation is realistic\n";
    else
        cout << "This simulation is not realistic\n";
    

    return 0;
}

/* 
 * Function that randomly outputs 1 or 0
 */
int flip() {

    return rand() % 2;

}

/*
 * Function that returns 1 when the number of tails in proportion to the number of heads
 * is between 45% and 55%. Returns 0 otherwise
 */
int valid(int heads, int tails) {

    int n = tails + heads;
    int percentage;

    percentage = (tails * 100)/n;

    if ((percentage < 45) || (percentage > 55))
        return 0;
    
    return 1;
}
