#include <iostream>
using namespace std;

void increase(int &number, int delta);

int main()
{
    int a = 3;
    int *a_ptr = &a;
    cout << "a = " << a << "\n";           // We get the value
    cout << "a_ptr = " << a_ptr << "\n";   // We get the address
    cout << "*a_ptr = " << *a_ptr << "\n"; // We get the value stored in the address
    increase(a, 7);
    cout << "a = " << a;
    return 0;
}

void increase(int &number, int delta)
{
    number += delta;
}