#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Dog
{
	string name;
	unsigned int age{};
public:
	Dog(string s) :name(s) {}
	Dog(string s, unsigned int a) :name(s),age(a) {}
	void print(void) const
	{
		cout << "  " << name << " age: " << age;
	}
	Dog& set_age(unsigned int a) { age = a; return *this; }

};

int main(void)
{
	Dog fido("Fido"), rolf("Rolf"), pluto("Pluto", 10);
	vector< const Dog*> dogPtrs;

	dogPtrs.push_back(&fido);
	dogPtrs.push_back(&rolf);
	dogPtrs.push_back(&pluto);

	for (int i = 0; i < dogPtrs.size(); i++)
	{
		dogPtrs.at(i)->print(); // range check
		//dogPtrs[i]->print();
	}

	for (auto dptr : dogPtrs)
	{
		// dptr->set_age(3); // not allowed because of const Dog pointers
	}
	cout << endl;
	for (auto dptr : dogPtrs)
	{
		dptr->print();
	}



	return 0;
}
