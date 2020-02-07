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

// function with lvalue reference of type 'double' 
void *callByReference(double &d)
{
    void *ref{NULL};
    return &ref;
}

// function with lvalue reference of type 'long double'
void *callByReference(long double &d)
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
    cout << "d1 - ref1= "
         << (char *)callByReference(d1) 
          - (char *)&ref1 << endl;

    // compute address difference between function (parameter type 'long double') and reference
    cout << "d2 - ref1= "
         << (char *)callByReference(d2) 
          - (char *)&ref1 << endl;

    return 0;
}