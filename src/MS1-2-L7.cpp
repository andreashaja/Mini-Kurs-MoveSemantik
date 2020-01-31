#include <iostream>

using namespace std;

struct MyStruct
{
    int num;
    int *ptr;
};

// 1a
void callByConstReference(const double &d)
{
    // d = 23; // forbidden
}

// 2b
void callByConstReference(const MyStruct &m)
{
    //m.num = 23; // forbidden
    *m.ptr = 42;
}

int main()
{
    // 1b
    double d1{0.0};
    callByConstReference(d1);

    // 2c
    MyStruct m1{0, new int(0)};
    callByConstReference(m1);
    cout << "*m1.ptr= " << *m1.ptr << endl;

    return 0;
}