/* Author: Patricia Wilthew.
 * Description: This program reads an input file and counts
 * its random values. It returns the sum and average of the
 * numbers in the file
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{   
    int total_numbers = 0;
    int sum = 0;
    int number = 0;

    string name_of_file;
    cout << "Enter the filename: ";
    getline(cin, name_of_file); 

    ifstream infile;
    infile.open(name_of_file);

    if (infile.is_open())
    {   
        while (infile >> number)
        {
            total_numbers += 1;
            sum += number;
        }
    }
    else
    {
        cout << "Error opening file" << endl;
        exit(1);
    }        

    infile.close();
    cout << "Number of numbers: " << total_numbers << endl;
    cout << "Sum of the numbers: " << sum << endl;
    cout << "Average of the numbers: " << fixed << setprecision(2) << double(sum)/double(total_numbers) << endl;

    return 0;
}
