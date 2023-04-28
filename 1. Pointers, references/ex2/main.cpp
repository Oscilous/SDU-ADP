#include <iostream>

using namespace std;

void input_box_sides(int &lenght, int &width, int &height);
void calc_box_sides(int lenght, int width, int height, int &surface, int &volume);
void show_box_sides(int lenght, int width, int height, int surface, int volume);

int main()
{
  int x, y, z, volume, surface;
  input_box_sides(x, y, z);
  calc_box_sides(x, y, z, surface, volume);
  show_box_sides(x, y, z, surface, volume);
  return 0;
}

void input_box_sides(int &lenght, int &width, int &height)
{
  cout << "x:";
  cin >> lenght;
  cout << "y:";
  cin >> width;
  cout << "z:";
  cin >> height;
}
void calc_box_sides(int lenght, int width, int height, int &surface, int &volume)
{
  surface = lenght * width;
  volume = surface * height;
}
void show_box_sides(int lenght, int width, int height, int surface, int volume)
{
  cout << lenght << endl;
  cout << width << endl;
  cout << height << endl;
  cout << surface << endl;
  cout << volume << endl;
}