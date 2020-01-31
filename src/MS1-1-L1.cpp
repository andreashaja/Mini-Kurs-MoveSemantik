#include <iostream>

using namespace std;

int main()
{
    // 1
    void *ref0{NULL};
    cout << "ref0 = " << &ref0 << endl;

    // 2
    double d1{0.0};
    cout << "d1 = " << &d1 << endl;

    // 3
    cout << "d1 - ref0 = "
         << (char *)&d1 - (char *)&ref0 
         << endl;

    return 0;
}