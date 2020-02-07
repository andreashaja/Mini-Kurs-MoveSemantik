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

class MyCopy
{
public:
    // ressources managed by this class
    double *_myNumber;
    std::string _myName;

    MyCopy()
    {
        cout << "Constructor\n";
        _myNumber = new double{0.0};
    }

    ~MyCopy()
    {
        cout << "Destructor\n";
        delete _myNumber;
    }

    // helper function to print heap address and value of managed ressourced
    void printValueAndHandle()
    {
        cout << _myName << " heap address = "
             << _myNumber;

        cout << ", value = "
             << (_myNumber != nullptr ? *_myNumber : 0.0) << endl;
    }
};

int main()
{
    // create MyCopy instances and set members
    MyCopy s1;
    s1._myName = "s1";
    *s1._myNumber = 42.0;

    MyCopy s2;
    s2._myName = "s2";
    *s2._myNumber = 23.0;

    // print value and heap address of managed ressources
    s1.printValueAndHandle();
    s2.printValueAndHandle();

    // use default copy assignment and print value and heap address afterwards
    s2 = s1;
    s2.printValueAndHandle();

    return 0;
}