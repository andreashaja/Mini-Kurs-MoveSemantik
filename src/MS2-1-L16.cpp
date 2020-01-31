#include <iostream>

using namespace std;

void passValue(int &&param)
{
    cout << "Rvalue\n";
}

void passValue(int &param)
{
    cout << "Lvalue\n";
}

int main()
{
    // 1
    int i{5};
    int &lv_ref = i;
    // int &lv_ref = 5; // Error

    // 2
    int &&rv_ref = 10;
    // int &&rv_ref = i; // Error
    rv_ref = 20;
    cout << "rv_ref = " << rv_ref << endl;

    // 3
    passValue(i);
    passValue(5);

    // 4
    passValue(rv_ref); 

    return 0;
}
