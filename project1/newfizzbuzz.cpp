/* Author: Patricia Wilthew.
 * Description: Prints numbers from 1 to 100. When a number is divisible by
 *  specific numbers, a specific word would be printed instead.
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int i;
    int count = 0;

    for (i = 1; i <= 100; i++){

        if ((i%3)==0 && (i%5)==0)
            cout << setw(10) << "FizzBuzz";
        else if ((i%3)==0 && (i%7)==0)
            cout << setw(10) << "FizzWoof";
        else if ((i%5)==0 && (i%7)==0)
            cout << setw(10) << "BuzzWoof";
        else if ((i%3)==0) 
            cout << setw(10) << "Fizz";
        else if ((i%5)==0)
            cout << setw(10) << "Buzz";
        else if ((i%7)==0)
            cout << setw(10) << "Woof";
        else 
            cout << setw(10) << i;

        count++;

        if (count == 5) {
            count = 0;
            cout << endl;
        }
    }

    return 0;
}
