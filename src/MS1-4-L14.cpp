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
	// create lvalue reference and use it to modify an lvalue
	int l{0};
	int &l_ref = l;
	l_ref = 5;
	cout << "l = " << l << endl;

	// try to assign an rvalue to an lvalue reference
	// int &ref = 5; // Fehler

	return 0;
}