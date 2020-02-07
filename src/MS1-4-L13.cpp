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

int main()
{
	// create some lvalues (i.e. variables)
	int i{0}; // i = Lvalue

	int j{5}; // j = Lvalue
	j = i;	  // j = Lvalue, i = Lvalue

	// assign rvalue (i.e. temporary object without identifier) to lvalue
	int k = i + j; // k = Lvalue, i+j = Rvalue

	// assign address (which is temporary and thus an rvalue) of an lvalue to another lvalue
	int *p = &i; // p = Lvalue, &i = Rvalue
	// 5 = i;      // forbidden
	// &i = p;     // forbidden

	return 0;
}
