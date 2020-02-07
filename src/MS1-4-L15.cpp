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

// create custom class that illustrates the difference between return-by-copy and return-by-reference
class MyClass
{
public:
    int _val;
    MyClass(int val) { _val = val; }
    ~MyClass() { cout << "~MyClass (_val=" << _val << ")\n"; }
    MyClass returnCopy() { return *this; }
    MyClass &returnReference() { return *this; } // note the ampersand before the function identifier
};

// function that has an lvalue reference as its parameter
void myFun1(int &param)
{
    param *= 2; // directly modify the lvalue behind the reference
}

int main()
{
    // create integer and pass it to function that modifies it using an lvalue reference
    int i{0};
    myFun1(i);
    cout << "i = " << i << endl;

    // create instance of MyClass and use 'return-by-copy'
    MyClass mc1(1);
    cout << "mc1._val (copy) = "
         << mc1.returnCopy()._val << endl;

    // create instance of MyClass and use 'return-by-reference' (note the number of destructor calls!)
    MyClass mc2(2);
    cout << "mc2._val (reference) = "
         << mc2.returnReference()._val << endl;

    

    return 0;
}