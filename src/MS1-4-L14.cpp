#include <iostream>

using namespace std;

int main()
{
	// 1
	int l{0};
  int &l_ref = l;
  l_ref = 5; 
  cout << "l = " << l << endl;

	// 2
	// int &ref = 5; // Fehler

	return 0;
}