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
#include "RelayRunner.h"

int Baton::idCnt = 0;

Baton::Baton()
{
    idCnt++;
    std::cout << "No. of Batons = " << idCnt << std::endl;
}

Baton::~Baton()
{
    idCnt--;
    std::cout << "No. of Batons = " << idCnt << std::endl;
}

// constructor
RelayRunner::RelayRunner(Baton *baton) : _pace{170}, _totalTime{0.0}, _totalDistance{0.0}
{
    _baton = baton;
    //std::cout << "Runner '" << this << "' CONSTRUCTED " << std::endl;
}

// destructor
RelayRunner::~RelayRunner()
{
    //std::cout << "Runner '" << this << "' DESTROYED" << (_baton != nullptr ? "(delete)" : " ") << std::endl;
    std::cout << "Runner '" << this << "' DESTROYED (_baton = " << _baton << ")\n";
    // deallocate heap memory
    delete _baton;
}

// copy constructor
RelayRunner::RelayRunner(RelayRunner &source)
{
    std::cout << "Runner '" << this << "' COPIED from '" << &source << "'\n";

    // allocate and copy heap memory
    if (source._baton != nullptr)
    {
        _baton = new Baton();     // allocate memory on heap for weight resource
        *_baton = *source._baton; // copy content from source to target (this)
        delete source._baton;     // delete handle at source to avoid two permanent baton instances
        source._baton = nullptr;  // avoids double-delete but requires argument to be non-const (very unusual)
    }
}

// copy assignment operator
RelayRunner &RelayRunner::operator=(RelayRunner &source)
{
    std::cout << "Runner '" << this << "' COPIED (=) from '" << &source << "'\n";

    // protect against self-assignment
    if (&source == this)
        return *this;

    // release resource this object might be holding
    delete _baton;

    // copy resource from source
    if (source._baton != nullptr)
    {
        _baton = new Baton();     // allocate memory on heap for weight resource
        *_baton = *source._baton; // copy content from source to target (this)
        delete source._baton;     // delete handle at source to avoid two permanent baton instances
        source._baton = nullptr;  // avoids double-delete but requires argument to be non-const (very unusual)
    }

    return *this;
}

// move constructor
RelayRunner::RelayRunner(RelayRunner &&source)
{
    std::cout << "Runner '" << this << "' MOVED from '" << &source << "'\n";

    _baton = source._baton;  // switch pointer from source to target
    source._baton = nullptr; // invalidate source pointer
}

// move assignment operator
RelayRunner &RelayRunner::operator=(RelayRunner &&source)
{
    std::cout << "Runner '" << this << "' MOVED (=) from '" << &source << "'\n";

    if (this == &source) // protect agains self-assignment
        return *this;

    if (_baton != nullptr) // delete pre-existing heap resource
        delete _baton;

    _baton = source._baton;  // switch pointer from source to target
    source._baton = nullptr; // invalidate source pointer

    return *this;
}