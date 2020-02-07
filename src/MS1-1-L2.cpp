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

// define local variable and return its address on the stack 
void *myFunc()
{
    void *ref{NULL};
    return &ref;
}

int main()
{
	// compute difference between stack bottom and local variable in scope of myFunc
    void *ref0{NULL};
    cout << "myFunc - ref0 = "
         << (char *)myFunc() - (char *)&ref0
         << endl;

	// compute difference between stack bottom and current stack position after function call
    void *ref1{NULL};
    cout << "ref1 - ref0 = "
         << (char *)&ref1 - (char *)&ref0
         << endl;

    return 0;
}