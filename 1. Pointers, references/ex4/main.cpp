#include <iostream>

using namespace std;

void minMax(int &a, int &b, int &c, int min, int max);

int main()
{
  int a = 9, b = 18, c = 1, min = NULL, max = NULL;
  minMax(a, b, c, min, max);
  return 0;
}

void minMax(int &a, int &b, int &c, int min, int max)
{
  min = a;
  max = a;
  if (min > b)
  {
    min = b;
  }
  else if (b > max)
  {
    max = b;
  }

  if (min > c)
  {
    min = c;
  }
  else if (c > max)
  {
    max = c;
  }

  cout << "Max:" << max << endl;
  cout << "Min:" << min << endl;
}