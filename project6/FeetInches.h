  /* Author: Patricia Wilthew.
   * Description: The FeetInches class holds distances or
   * measurements expressed in feet and inches
   */
#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <cstdlib>
#include <iostream>
using namespace std;

class FeetInches
{
    private:
        int feet;        // To hold a number of feet
        int inches;      // To hold a number of inches

    public:
       // Constructor
        FeetInches(int f = 0, int i = 0)
        { 
            feet = f;
            inches = i;
        }
        
        // Mutator functions
        void setFeet(int f)
        { 
            feet = f; 
        }

        void setInches(int i)
        { 
            inches = i;
        }

        // Accessor functions
        int getFeet() const
        { 
            return feet;
        }

        int getInches() const
        { 
            return inches;
        }

        // Overloaded operator functions
        bool operator > (const FeetInches &right)
        {
            bool load;
            if (feet > right.feet)
              load = true;
            else if (feet = right.feet and inches > right.inches)
              load = true;
            else
              load = false;

            return load;
        }

        bool operator < (const FeetInches &right)
        {
            bool load;
            if (feet < right.feet)
              load = true;
            else if (feet = right.feet and inches < right.inches)
              load = true;
            else
              load = false;

            return load;
        }

        friend istream &operator >> (istream &is, FeetInches &f)
        {
            char ch;

            is >> f.feet;
            is >> ch;
            is >> f.inches;

            return is;
        }

        friend ostream &operator << (ostream &os, const FeetInches &f)
        {
            os << f.feet << " feet, and " << f.inches << " inches ";

            return os;
        }
};

#endif
