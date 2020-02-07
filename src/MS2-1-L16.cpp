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

// function assigns argument to an rvalue reference
void passValue(int &&param)
{
    cout << "Rvalue\n";
}

// function assigns argument to an lvalue reference
void passValue(int &param)
{
    cout << "Lvalue\n";
}

int main()
{
    // create lvalue and lvalue reference
    int i{5};
    int &lv_ref = i;
    // int &lv_ref = 5; // Error

    // create rvalue reference and link it to temporary value '10'
    int &&rv_ref = 10;
    // int &&rv_ref = i; // Error

    // change temporary value using the rvalue reference
    rv_ref = 20;
    cout << "rv_ref = " << rv_ref << endl;

    // pass lvalue and rvalue to functions
    passValue(i);
    passValue(5);

    // pass rvalue reference to function (note which version is called!)
    passValue(rv_ref); 

    return 0;
}
