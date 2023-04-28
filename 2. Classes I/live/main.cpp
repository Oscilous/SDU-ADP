#include <iostream>
#include <vector>

using namespace std;

class Date
{
private:
  unsigned int day{1};
  unsigned int month{1};
  unsigned int year{0};

public:
  Date(unsigned int d, unsigned int m, unsigned int y) : day{d}, month{m}, year{y} {}
  Date(unsigned int d, unsigned int m) : day(d), month(m), year(2023) {}
  void print(void) const
  {
    cout << "(" << day << "-" << month << "-" << year << ")";
  }
};

class Period
{
private:
  Date start;
  Date end;

public:
  Period(Date s, Date e) : start{s}, end{e} {}
  void print(void)
  {
    start.print();
    cout << "-";
    end.print();
  }
};

int main()
{
  Date today(10, 2);
  Date tommorow(11, 2, 1000);
  Period winter(today, tommorow);
  // Print attribute values
  today.print();
  winter.print();

  vector<Date> birthdays;
  birthdays.push_back(Date(11, 7));
  birthdays.push_back(Date(11, 4));
  birthdays.push_back(Date(13, 7));
  for (auto i : birthdays)
  {
    cout << endl;
    i.print();
  }
  return 0;
}