#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// 1
void allocStack()
{
    double d[100];
}

// 2
void allocHeap()
{
    double *d = new double[100];
    delete[] d; 
}

int main()
{
    // 3
    auto t1 = high_resolution_clock::now();
    allocStack();
    auto t2 = high_resolution_clock::now();
    cout << "stack time = " << duration_cast<nanoseconds>(t2 - t1).count() << endl;

    // 4
    t1 = high_resolution_clock::now();
    allocHeap();
	  t2 = high_resolution_clock::now();
    cout << "heap time = " << duration_cast<nanoseconds>(t2 - t1).count() << endl;

    return 0;
}