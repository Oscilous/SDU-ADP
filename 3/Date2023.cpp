#include<iostream>
#include<vector>

using namespace std;


class Date
{
	friend class Period;
  private:
	int month;
	int day;
	int year;
	static int date_count;
  public:
	Date(int m, int d, int y) : month(m), day(d), year{ y } {date_count++; }
	Date(int m, int d) : month(m), day(d), year{ 2023 } {date_count++; }
	Date(const Date &d) : month(d.month), day(d.day), year{ d.year } {date_count++; } // privacy is on the class level
	~Date() { this->date_count--; }
	static int get_date_count(void) { return date_count; }
	//Date* set_day(int d) { day = d; return this; }
	//Date* set_month(int m) { month = m; return this; }
	//Date* set_year(int d) { day = d; return this; }
	
	Date& set_day(int d) { day = d; return *this; }
	Date& set_month(int m) { month = m; return *this; }
	Date& set_year(int y) { year = y; return *this; }


	void print(void) const
	{  
		
		cout << "(" << month << "," << day << "," << year << ")";
	}
};
int Date::date_count = 0;

class Period
{
  private:
	  Date start;
	  Date end;
  public:
	  Period(Date s, Date e) : start(s), end(e) {}
	  void print(void)
	  {
		  start.print(); cout << "-"; end.print();
	  }
	  int length(void)
	  {
		  if (end.month == start.month) return end.day - start.day;
		  else return 0; // homework
	  }

};

int main(void)
{ 
	cout << endl << " date count: " << Date::get_date_count() << endl;
	Date today(2, 10);
	Date Joe_birthday(12, 24), Jill(Joe_birthday); // copy constructor called
	today.print();
	cout << endl << " date count: " << Date::get_date_count() << endl;
	{
	  Period winter_holiday(Date(2, 11), Date(2, 19));
	  winter_holiday.print();
	  cout << endl << " date count: " << Date::get_date_count() << endl;
	  cout << " length of winter holiday: " << winter_holiday.length();
	}
	vector<Date> birth_days;
	
	cout << endl << " date count: " << Date::get_date_count() << endl;
	birth_days.push_back(Date(11, 7));
	birth_days.push_back(Joe_birthday);
	birth_days.push_back(Jill);

	for (auto b : birth_days)
	{
		b.print(); cout << " ";
	}

	today.set_day(17).set_month(2).set_year(2023); // cascading calls
	cout << " today: ";
	today.print();

	

	
	return 0;
}