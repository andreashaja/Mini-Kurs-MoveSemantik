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
#include <chrono>

using namespace std;
using namespace std::chrono;

// allocate array on stack locally within function scope
void allocStack()
{
    double d[100];
}

// allocate array on heap locally within function scope
void allocHeap()
{
    double *d = new double[100];
    delete[] d; 
}

int main()
{
    // compute execution time for allocating memory on the stack
    auto t1 = high_resolution_clock::now();
    allocStack();
    auto t2 = high_resolution_clock::now();
    cout << "stack time = " << duration_cast<nanoseconds>(t2 - t1).count() << endl;

    // compute execution time for allocating memory on the heap
    t1 = high_resolution_clock::now();
    allocHeap();
	  t2 = high_resolution_clock::now();
    cout << "heap time = " << duration_cast<nanoseconds>(t2 - t1).count() << endl;

    return 0;
}