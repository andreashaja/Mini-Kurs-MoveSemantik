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

// initialize counter for instances of MovableClass
int idCnt = 0;

// create for managing heap memory (template enables arbitrary data types)
template <class T>
class MovableClass
{
private:
    // managed heap ressource and id of class instance
    T *_ressource;
    int _id;

public:
    MovableClass(T *ptr = nullptr)
    {
        _ressource = ptr;
        _id = ++idCnt;
        cout << _id << " Constructor " << sizeof(*ptr) << " byte\n";
    }

    // Rule of Three
    ~MovableClass()
    {
        cout << _id << " Destructor " << (_ressource != nullptr ? "(delete)\n" : "\n");
        delete _ressource;
    }

    MovableClass(const MovableClass &source)
    {
        // check for validity of source ressource
        if (source._ressource != nullptr)
        {
            _ressource = new T;
            *_ressource = *source._ressource;
        }

        _id = ++idCnt; // increment instance counter
        cout << _id << " Copy Constr. from " << source._id << "\n";
    }

    MovableClass &operator=(const MovableClass &source)
    {
        cout << _id << " Copy Assignm. from " << source._id << "\n";

        // protect against self assignment
        if (&source == this)
            return *this;

        // delete heap ressource and invalidate pointer
        delete _ressource;
        _ressource = nullptr;

        // check for validity of source ressource
        if (source._ressource != nullptr)
        {
            // allocate new memory and copy ressource (memory could be reused for more efficiency!)
            _ressource = new T;
            *_ressource = *source._ressource;
        }

        return *this;
    }

    // Rule of Five
    MovableClass(MovableClass &&source)
    {
        // switch ressource pointer and invalidate source ressource
        _ressource = source._ressource;
        source._ressource = nullptr;

        _id = ++idCnt; // increment instance counter
        cout << _id << " Move Constr. from " << source._id << "\n";
    }

    MovableClass &operator=(MovableClass &&source)
    {
        cout << _id << " Move Assigm. from " << source._id << "\n";

        // protect against self assignment
        if (&source == this)
            return *this;

        // switch ressource pointer and invalidate source ressource
        _ressource = source._ressource;
        source._ressource = nullptr;

        return *this;
    }
};

int main()
{
    // create instances of MovableClass with different data types
    MovableClass<double> mc_d(new double);
    MovableClass<long double> mc_ld(new long double);

    // use copy constructor
    MovableClass<double> mc_d2(mc_d);
    MovableClass<double> mc_d3 = mc_d;
    // MovableClass<double> mc_d4(mc_ld); // error

    // use move constructor
    MovableClass<double> mc_d5(std::move(mc_d));

    // use move assignment operator
    mc_d = std::move(mc_d5);

    return 0;
}