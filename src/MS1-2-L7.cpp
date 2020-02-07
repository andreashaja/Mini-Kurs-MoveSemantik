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

// create customized data structure
struct MyStruct
{
    int num;
    int *ptr;
};

// function accepts argument as 'read-only' reference
void callByConstReference(const double &d)
{
    // d = 23; // forbidden
}

// function accepts customized data structure as 'read-only'...
void callByConstReference(const MyStruct &m)
{
    //m.num = 23; // forbidden
    *m.ptr = 42; // ... but allows to change the heap content!
}

int main()
{
    // instantiate double variable and pass it to function as 'const reference'
    double d1{0.0};
    callByConstReference(d1);

    // instantiate data structure including heap memory and pass it to function as 'const reference'
    MyStruct m1{0, new int(0)};
    callByConstReference(m1);
    cout << "*m1.ptr= " << *m1.ptr << endl; // observe how heap content is modified

    return 0;
}