/* Author: Patricia Wilthew.
 * Description: Used to implement Employee objects
 */
using namespace std;
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include "Employee.h"

int main() {

    Employee A("Peter Paterson", 4000);
    Employee B;
    string name;
    double salary;

    //getting employees info
    cout << "Enter an employee name: ";
    getline(cin, name);
    B.change_name(name);

    cout << "Enter the employee's monthly salary: ";
    cin >> salary;
    B.change_salary(salary);

    //printing employees info
    cout << endl << "Here are the employees and their yearly salaries" << endl; 

    cout << A.get_name() << ": ";
    cout << "$" << A.get_salary()*12 << endl;

    cout << B.get_name() << ": ";
    cout << "$" << B.get_salary()*12 << endl;

    //giving a 10% raise
    A.change_salary(A.get_salary()*1.10);
    B.change_salary(B.get_salary()*1.10);

    //printing employees info again
    cout << endl << "Here are the employees and their yearly salaries after the 10% raise" << endl;

    cout << A.get_name() << ": ";
    cout << "$" << A.get_salary()*12 << endl;
     
    cout << B.get_name() << ": ";
    cout << "$" << B.get_salary()*12 << endl;

    return 1;
}

