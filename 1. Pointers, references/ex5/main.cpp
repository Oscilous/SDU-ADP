#include <iostream>

using namespace std;

void minMax(int &a, int &b, int &c);

int main()
{
  int a = 2, b = 1, c = 0;
  minMax(a, b, c);
  return 0;
}

void minMax(int &a, int &b, int &c)
{
  if (a > b)
  {
    int temp = a;
    a = b;
    b = temp; // 6 4 2
  }
  if (b < a)
  {
    int temp = b;
    b = a;
    a = temp;
  }
  if (b > c)
  {
    int temp = b;
    b = c;
    c = temp; // 6 4 2
  }
  cout << "a:" << a << endl;
  cout << "b:" << b << endl;
  cout << "c:" << c << endl;
}