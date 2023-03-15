#include<iostream>
#include <vector>

using namespace std;


class Coyota_dealer_affiliated
{
    public:
        virtual string write_letter_to(string s){
            return "Dear" + s;
        }
};

class Person : public Coyota_dealer_affiliated
{
    private:
        string name, address;
    public:
        Person(string n, string a) : name{n}, address{a} {} 
        virtual string to_string(void){
            return name + " " + address;
        }
        string get_name(void){
            return name;
        }
        string get_address(void){
            return address;
        }
};

class Japanese_mechanic : public Person
{
    private:
        double monthly_salary;
    public:
        Japanese_mechanic(string name, string address) : Person(name, address) {};
        string to_string(void) override
        {
            return Person::to_string();
        }
};


class Customer : public Person{
    friend ostream& operator<<(ostream& out, Customer c);
    friend void print_cost(void);
    private:
        int customer_id;
        double account;
        static int highest_id;

    public:
        Customer(string name, string address, double a) : Person(name, address), customer_id{highest_id}, account{a} {
            highest_id++;

            } 
        string to_string(void) override
        {
            return Person::to_string() + " " + std::to_string(customer_id);
        }
        string write_letter_to(string s) override
        {
            return "Dear, " + get_name() + " " + get_address() + s;
        }
};
int Customer::highest_id {0};

ostream& operator<<(ostream& out, Customer c)
{
	out << c.to_string();
	return out;
}


class Employee : public Person{
    private:
        int employee_id;
        static int highest_id;
    public:
        Employee(string name, string address) : Person(name, address), employee_id{highest_id} {highest_id++;} 
        string to_string(void) override
        {
            return Person::to_string() + " " + std::to_string(employee_id);
        }
        virtual double calculate_salary(void)
        {
            return 100.0;
        }
};
int Employee::highest_id {0};

class Mechanic : public Employee{
    private:
        double hourly_salary, hours;
    public:
        Mechanic(string name, string address) : Employee(name, address) {} 
        string to_string(void) override
        {
            return "Mechanic " + Employee::to_string();
        }
        double calculate_salary(void) override
        {
            return 150.0;
        }
        string write_letter_to(string s) override
        {
            return "Dear, mechanic " + get_name() + " " + get_address() + s;
        }
};

class Sales_person : public Employee{
    private:
        double sale, provision;
    public:
    Sales_person(string name, string address) : Employee(name, address) {} 
        string to_string(void) override
        {
            return "Sales " + Employee::to_string();
        } 
        virtual double calculate_salary(void) override
        {
            return 200.0;
        }
        string write_letter_to(string s) override
        {
            return "Dear, Sales " + get_name() + " " + get_address() + s;
        }
};

class Director : public Employee{
    private:
        string company_car ;
        double monthly_salary;
    public:
    Director(string name, string address) : Employee(name, address) {} 
        string to_string(void) override
        {
            return "Director " + Employee::to_string();
        }
        virtual double calculate_salary(void) override
        {
            return 999.0;
        }
        string write_letter_to(string s) override
        {
            return "Dear, Director " + get_name() + " " + get_address() + s;
        }
};

class Foreign_worker : public Japanese_mechanic, public Mechanic
{
    public:
        Foreign_worker(string name, string address) : Japanese_mechanic(name, address), Mechanic(name, address) {}
        string to_string(void) override
        {
            return Japanese_mechanic::to_string() + Mechanic::to_string();
        }
};

int main (void){
    vector<Customer *> customers{};

    
    Customer c1("Joe", "Street 8", 4.0);
    customers.push_back(&c1);
    Customer c2("Jon", "Street 7", 5.0);
    customers.push_back(&c2);
    Customer c3("Jo", "Street 6", 5.0);
    customers.push_back(&c3);

    vector<Employee *> employees{};

    Sales_person s1("Anna", "Street 7");  
    employees.push_back(&s1);
    Director d1("John", "Big street 8");
    employees.push_back(&d1);
    Mechanic m1("Matty", "AK 6");
    employees.push_back(&m1); 
    for (auto i : customers) {
        cout << i->to_string() << endl;
    }
    cout << c1 << endl;

    for (auto i : employees) {
        cout << i->to_string() << endl;
    }
    double sum = 0.0;
    for (auto i : employees) {
        sum += i->calculate_salary();
    }
    cout << "Sum: " << sum << endl << endl << endl;

    for (auto i : customers){
        cout << i->write_letter_to(" easter")<<endl;
    }

    vector <Person*> dealers{};    
    dealers.insert(dealers.end(), customers.begin(), customers.end());
    dealers.insert(dealers.end(), employees.begin(), employees.end());
    for (auto i : dealers) {
        cout << i->write_letter_to(" Bla bla bla") << endl;
    }
    
    Japanese_mechanic jm("Ito", "Kyoto");

    cout << jm.to_string() << endl;

    return 0;
}