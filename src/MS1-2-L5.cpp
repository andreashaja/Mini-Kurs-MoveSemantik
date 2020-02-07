/* ---------------------------------------------------------------------
 * The Fearless Engineer - Mini-Kurs "Move Semantik in C++"
 * Copyright (C) 2020, Dr. Andreas Haja.  
 *
 * You should have received a copy of the MIT License
 * along with this program. If not, see https://opensource.org/licenses/MIT.
 *
 * http://www.thefearlessengineer.com
 * ----------------------------------------------------------------------
 */

#include <iostream>

using namespace std;

// function accepts argument "by-value" and thus creates a local copy
void *callByValue(double d)
{
    // return stack address of local variable to measure function memory requirements
    void *ref{NULL};
    return &ref;
}

// identical to function above buth with a larger data type
void *callByValue(long double d)
{
    void *ref{NULL};
    return &ref;
}

int main()
{
    // instantiate two different data types and print memory requirements
    double d1{0.0};
    long double d2{0.0};
    cout << "d1= " << sizeof(d1) << " byte, "
         << "d2= " << sizeof(d2) << " byte\n";

    // compute address difference between function (parameter type 'double') and reference
    void *ref1{NULL};
    cout << "callByValue(d1) - ref1= "
         << (char *)callByValue(d1) 
          - (char *)&ref1 << endl;

    // compute address difference between function (parameter type 'long double') and reference
    cout << "callByValue(d2) - ref1= "
         << (char *)callByValue(d2) 
          - (char *)&ref1 << endl;

    return 0;
}