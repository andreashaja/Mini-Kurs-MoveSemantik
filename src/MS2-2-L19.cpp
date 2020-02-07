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

    // helper function that prints value and address of heap ressource
    void printValueAndHandle()
    {
        cout << _id << " heap=" << _ressource;
        cout << ", *heap=" << (_ressource != nullptr ? *_ressource : 0.0) << endl;
    }
};

// template function that assigns argument to an rvalue reference
template <class T>
void moveObjectHere1(MovableClass<T> &&obj)
{
    obj.printValueAndHandle();
}

// template function that copies the argument by-value
template <class T>
void moveObjectHere2(MovableClass<T> obj)
{
    obj.printValueAndHandle();
}

int main()
{
    // create new instance of MyClass and move it into function scope twice (note how the second call differs from the first)
    MovableClass<double> mc_d1(new double{1});
    moveObjectHere1<double>(std::move(mc_d1));
    moveObjectHere1<double>(std::move(mc_d1));

    // create new instance of MyClass and pass it to second function by-value instead of by-rvalue-reference
    MovableClass<double> mc_d2(new double{2});
    moveObjectHere2<double>(std::move(mc_d2));
    moveObjectHere2<double>(std::move(mc_d2));

    return 0;
}