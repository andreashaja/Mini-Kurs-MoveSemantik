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

// create class that implements the 'Rule of Three' (note that no functionality is included yet)
class MyClass
{
public:

	MyClass()
    {
        cout << "Constructor\n";
    }

    ~MyClass()
    {
        cout << "Destructor\n";
    }

    MyClass(const MyClass &source)
    {
        cout << "Copy Constructor\n";
    }

    MyClass &operator=(const MyClass &source)
    {
        cout << "Copy Assignment\n";
        return *this;
    }
};


int main()
{
    // create two instances (calls constructor)
    MyClass m1, m2;

    // use copy assignment operator
    m2 = m1;

    // use copy constructor
    MyClass m3(m1);

    // copy constructor or copy assignment?
    MyClass m4 = m1;

    return 0;
}