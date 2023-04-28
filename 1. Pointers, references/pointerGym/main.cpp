#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
  int a = 2;
  int b(5); // int constructor called
  int c{3}; // c++17 initialization

  int *a_ptr = &a;
  int *b_ptr(&b);
  int *c_ptr{&c};

  int sum = *a_ptr + *b_ptr + *c_ptr;
  int &xx = *new int{7}; // dynamically added variable, benefit of these is that ou can delete them to free space
  int **ptrptr = &a_ptr;
  auto &aa = a; // aa is another name for a
  // auto makes the compiler find the type of a and assign to aa

  int list[] = {a, b, c};
  for (auto i : list)
  {
    cout << setw(20) << " i " << setw(20) << &i << setw(20) << i << endl;
  }
  cout << setw(20) << " name " << setw(20) << " address " << setw(20) << " value " << endl;
  cout << setw(20) << " a " << setw(20) << &a << setw(20) << a << endl;
  cout << setw(20) << " b " << setw(20) << &b << setw(20) << b << endl;
  cout << setw(20) << " c " << setw(20) << &c << setw(20) << c << endl;
  cout << setw(20) << " a_ptr " << setw(20) << &a_ptr << setw(20) << a_ptr << endl;
  cout << setw(20) << " b_ptr " << setw(20) << &b_ptr << setw(20) << b_ptr << endl;
  cout << setw(20) << " c_ptr " << setw(20) << &c_ptr << setw(20) << c_ptr << endl;
  cout << setw(20) << " sum " << setw(20) << &sum << setw(20) << sum << endl;
  cout << setw(20) << " xx " << setw(20) << &xx << setw(20) << xx << endl;
  cout << setw(20) << " ptrptr " << setw(20) << &ptrptr << setw(20) << ptrptr << endl;
  
  return 0;
}