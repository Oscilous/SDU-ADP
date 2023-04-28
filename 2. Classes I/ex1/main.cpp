#include <iostream>

using namespace std;

class Counter
{
private:
  int counter_value{0};

public:
  void tick(void)
  {
    counter_value++;
  }
  void reset(void)
  {
    counter_value = 0;
  }
  auto get(void)
  {
    return counter_value;
  }
};

int main(void)
{
  Counter myCounter;

  myCounter.tick();
  cout << myCounter.get() << endl;
  myCounter.reset();
  cout << myCounter.get() << endl;

  return 0;
}