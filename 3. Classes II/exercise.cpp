#include <iostream>
#include <vector>


using namespace std;

class Date
{
  private:
	int month;
	int day;
	int year;
  public:
	Date(int m, int d, int y) : month(m), day(d), year{ y } {}
	Date(int m, int d) : month(m), day(d), year{ 2023 } {}
	Date(const Date &d) : month(d.month), day(d.day), year{ d.year } {} // privacy is on the class level

	Date& set_day(int d) { day = d; return *this; }
	Date& set_month(int m) { month = m; return *this; }
	Date& set_year(int y) { year = y; return *this; }


	void print(void) const
	{  
		
		cout << "(" << month << "," << day << "," << year << ")";
	}
};

class Person{
private:
    string name;
    Date birth_date;
    Person *mother_ptr;
    Person *father_ptr;
    vector<Person> children = {};

void add_child(Person Child){
    //Person.children->push_back(Child);
}
public:
    Person(string n, Date b) : name(n), birth_date(b) {}
    Person(string n, Date b, Person &m_ptr, Person &f_ptr) : name(n), birth_date(b), mother_ptr(&m_ptr), father_ptr(&f_ptr) {}
    void print(void)
	{  
		cout << "Name: " << name << endl;
        cout << "Birth: ";
		birth_date.print();
        cout << endl;
        cout << endl;
	}
};

int main(){
    Date birth(13,3,2017);
    Person MyPerson("Andre", birth);

    MyPerson.print();

    return 0;
}

//Train pointers and refrences, usually passing into function we use refrences
//Hint for the last preorder and postorder traversial