#include <iostream>

using namespace std;

// 1b
void *myFunc()
{
    void *ref{NULL};
    return &ref;
}

int main()
{
	// 1a
    void *ref0{NULL};
    cout << "myFunc - ref0 = "
         << (char *)myFunc() - (char *)&ref0
         << endl;

	// 2
    void *ref1{NULL};
    cout << "ref1 - ref0 = "
         << (char *)&ref1 - (char *)&ref0
         << endl;

    return 0;
}