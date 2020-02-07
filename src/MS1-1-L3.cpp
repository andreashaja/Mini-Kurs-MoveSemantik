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

int main()
{
     // create variables on the heap
     double *d0 = new double;
     double *d1 = new double[10];

     // print both heap and stack address
     cout << "d1 (heap) = " << d1 << endl;
     cout << "d1 (stack) = " << &d1 << endl;

     // compute difference between stack addresses (observe sign and magnitude)
     cout << "d1 (stack) - d0 (stack) = "
          << (char *)&d1 - (char *)&d0 << endl;

     // compute difference between heap addresses (observe sign and magnitude)
     cout << "d1 (heap) - d0 (heap) = "
          << (char *)&d1[9] - (char *)d0 << endl;

     // delete heap memory
     delete d0;
     delete[] d1;

     return 0;
}