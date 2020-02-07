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

#ifndef _RELAYRUNNER_H_
#define _RELAYRUNNER_H_

#include <string>

class Baton
{
private:
    int _weight[1000]; // large block of memory which denotes the baton weight
    static int idCnt;  // counts the number of Baton instances

public:
    Baton();
    ~Baton();
};

class RelayRunner
{
private:
    double _pace;          // pace of runner in min/km
    double _totalTime;     // accumulates time spent running
    double _totalDistance; // accumulates distance being run
    Baton *_baton;         // the baton to be passed between runners

public:
    RelayRunner(Baton *baton = nullptr); // default constructor
    //Baton *handOverBaton(Baton *baton = nullptr); // allocates memory on the heap

    // Rule of Three
    ~RelayRunner();                              // destructor
    RelayRunner(RelayRunner &source);            // copy constructor
    RelayRunner &operator=(RelayRunner &source); // copy assignment operator (non-const is very unusual)

    // Rule of Five
    RelayRunner(RelayRunner &&source);            // move constructor
    RelayRunner &operator=(RelayRunner &&source); // move assignment operator
};

#endif // _RELAYRUNNER_H_