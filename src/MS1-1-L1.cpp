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

int main()
{
    // define void pointer as base reference for the stack bottom
    void *ref0{NULL};
    cout << "ref0 = " << &ref0 << endl;

    // define variable on the stack (compare address to stack bottom ref0)
    double d1{0.0};
    cout << "d1 = " << &d1 << endl;

    // compute difference between variable and stack bottom (observe sign and magnitude )
    cout << "d1 - ref0 = "
         << (char *)&d1 - (char *)&ref0 
         << endl;

    return 0;
}