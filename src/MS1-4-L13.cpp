#include <iostream>

int main()
{
	// 1
    int i{0};      // i = Lvalue

	// 2
	int j{5};      // j = Lvalue
    j = i;         // j = Lvalue, i = Lvalue

	// 3
	int k = i + j; // k = Lvalue, i+j = Rvalue

	// 4
  int *p = &i;   // p = Lvalue, &i = Rvalue
  // 5 = i;      // Fehler
  // &i = p;     // Fehler

	return 0;
}

