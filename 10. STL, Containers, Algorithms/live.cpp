#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

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
		cout << "  " << name << " age: " << age << endl;
	}
	Dog& set_age(unsigned int a) { age = a; return *this; }
	unsigned int get_age(void) const { return age;}
	unsigned int get_name(void) const { return name.size();}
};

void dog_print(const Dog* cdptr) { cdptr->print(); }

struct Dog_name_cmp{
	bool operator()(const Dog* dog1, const Dog* dog2){ return dog1->get_name() > dog2->get_name(); }
}Dog_name_cmp;

int main(void)
{
	Dog fido("Fido", 1), rolf("Rolf", 12), pluto("Pluto", 10), anton("Anton", 3), joe("joe", 5);
	vector< const Dog*> dogPtrs;

	dogPtrs.push_back(&fido);
	dogPtrs.push_back(&rolf);
	dogPtrs.push_back(&pluto);
	dogPtrs.push_back(&anton);
	dogPtrs.push_back(&joe);

	/* Old way
	for(int i; i < dogPtrs.size(); i++){
		dogPtrs.at(i)->print();
	} 
	*/
	//New way with iterator
	/* The simplest
	for(auto i : dogPtrs){
		i->print();
	}
	*/
	//Iterators
	for(auto d_it = dogPtrs.cbegin(); d_it != dogPtrs.cend(); ++d_it){
		(*d_it)->print();
	} 
	//Second way of doing it
	for(auto d_it = cbegin(dogPtrs); d_it != cend(dogPtrs); ++d_it){
		(*d_it)->print();
	} 
	cout << endl;
	//Ascending in age
	sort(begin(dogPtrs), end(dogPtrs),
		[] ( const Dog* dog1, const Dog* dog2) { return dog1->get_age() < dog2->get_age(); });
	
	//For each way of doing it, requires a function
	//Might be used as a good thing, function can change the parameter
	for_each(cbegin(dogPtrs), cend(dogPtrs), dog_print);
	bool found = binary_search(cbegin(dogPtrs), cend(dogPtrs), &joe ,Dog_name_cmp);
	cout << (found ? "We found Joe" : "we did not :(") << endl;
	//Descend in name
	sort(begin(dogPtrs), end(dogPtrs), Dog_name_cmp);
	for_each(cbegin(dogPtrs), cend(dogPtrs), dog_print);

	int min_age = (*min_element(begin(dogPtrs), end(dogPtrs),
		[] ( const Dog* dog1, const Dog* dog2)
		{ return dog1->get_age() < dog2->get_age(); }))->get_age();
	cout << "Youngest age is " << min_age << endl;
	return 0;
}