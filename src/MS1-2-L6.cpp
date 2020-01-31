#include <iostream>

using namespace std;

void *callByReference(double &d)
{
    void *ref{NULL};
    return &ref;
}

void *callByReference(long double &d)
{
    void *ref{NULL};
    return &ref;
}

int main()
{
    double d1{0.0};
    long double d2{0.0};
    cout << "d1= " << sizeof(d1) << " byte, "
         << "d2= " << sizeof(d2) << " byte\n";

    void *ref1{NULL};
    cout << "d1 - ref1= "
         << (char *)callByReference(d1) 
          - (char *)&ref1 << endl;

    cout << "d2 - ref1= "
         << (char *)callByReference(d2) 
          - (char *)&ref1 << endl;

    return 0;
}