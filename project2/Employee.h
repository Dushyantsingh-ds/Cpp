/* Author: Patricia Wilthew.
 * Description: Definition of an Employee Object
 */
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

class Employee {
    private:
        string name;    //Full name of an employee
        double salary;  //Monthly salary of the employee

    public:
        /*
         * Default constructor
         */
        Employee() {
            name = "";
            salary = 0;
        }
        
        /*
         * 2 parameters constructor
         */
        Employee(string n, double s) {
            name = n;
            salary = s;
        }
        
        /*
         * Accessor: Returns the name member of an Employee object
         */
        string get_name() {
            return name;
        }

        /*
         * Accessor: Returns the salary member of an Employee object
         */
        double get_salary() {
            return salary;
        }

        /*
         * Mutator: Sets or changes the name member of an Employee object
         */
        void change_name(string newName) {
            name = newName;
        }

        /*
         * Mutator: Sets or changes the salary member of an Employee object
         */
        void change_salary(int newSalary) {
            salary = newSalary;
        }

};

#endif
