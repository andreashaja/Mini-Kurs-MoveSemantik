#include <iostream>

using namespace std;

class MyClass
{
public:

	MyClass()
    {
        cout << "Constructor\n";
    }

    ~MyClass()
    {
        cout << "Destructor\n";
    }

    MyClass(const MyClass &source)
    {
        cout << "Copy Constructor\n";
    }

    MyClass &operator=(const MyClass &source)
    {
        cout << "Copy Assignment\n";
        return *this;
    }
};


int main()
{
    // 1
    MyClass m1, m2;

    // 2
    m2 = m1;

    // 3
    MyClass m3(m1);

    // 4
    MyClass m4 = m1;

    return 0;
}