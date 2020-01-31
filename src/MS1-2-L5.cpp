#include <iostream>

using namespace std;

// 2a
void *callByValue(double d)
{
    void *ref{NULL};
    return &ref;
}

// 3a
void *callByValue(long double d)
{
    void *ref{NULL};
    return &ref;
}

int main()
{
    // 1
    double d1{0.0};
    long double d2{0.0};
    cout << "d1= " << sizeof(d1) << " byte, "
         << "d2= " << sizeof(d2) << " byte\n";

    // 2b
    void *ref1{NULL};
    cout << "d1 - ref1= "
         << (char *)callByValue(d1) 
          - (char *)&ref1 << endl;

    // 3b
    cout << "d2 - ref1= "
         << (char *)callByValue(d2) 
          - (char *)&ref1 << endl;

    return 0;
}