#include <iostream>

using namespace std;

//2a
class MyClass
{
public:
    int _val;
    MyClass(int val) { _val = val; }
    ~MyClass() { cout << "~MyClass\n"; }
    MyClass returnCopy() { return *this; }
    MyClass &returnReference() { return *this; }
};

// 1a
void myFun1(int &param)
{
    param *= 2;
}

int main()
{
    // 1b
    int m{10};
    myFun1(m);
    cout << "m = " << m << endl;

    // 2b
    MyClass mc(5);
    cout << "mc._val (copy) = "
         << mc.returnCopy()._val << endl;

    // 2c
    cout << "mc._val (reference) = "
         << mc.returnReference()._val << endl;

    return 0;
}