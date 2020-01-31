#include <iostream>

using namespace std;

int main()
{
    // 1
    double *d0 = new double;
    double *d1 = new double[10];

    // 2
    cout << "d1 (heap) = " << d1 << endl;
    cout << "d1 (stack) = " << &d1 << endl;

    // 3
    cout << "d1 (stack) - d0 (stack) = "
         << (char*)&d1 - (char*)&d0 << endl;

    cout << "d1 (heap) - d0 (heap) = "
         << (char*)&d1[9] - (char*)d0<< endl;

    // 4
    delete d0;
    delete[] d1;

    return 0;
}