#include <iostream>

using namespace std;

void rotate(int &a, int &b, int &c);

int main()
{
  int a = 2;
  int b = 4;
  int c = 6;
  rotate(a, b, c);
  cout << a << endl
       << b << endl
       << c << endl;
  return 0;
}

void rotate(int &a, int &b, int &c)
{
  int temp = a;
  a = c;
  c = temp; // 6 4 2
  temp = b;
  b = c;
  c = temp;
}