#include<iostream>
#include <vector>

using namespace std;

class Person{
    private:
        string name, address;
    public:
        Person(string n, string a) : name{n}, address{a} {} 
        string to_string(void){
            return name + " " + address;
        }
};

class Customer : public Person{
    friend ostream& operator<<(ostream& out, Customer c);
    friend void print_cost(void);
    private:
        int customer_id;
        double account;
        static int highest_id;
        static vector<Customer *> customers{};
    public:
        Customer(string name, string address, double a) : Person(name, address), customer_id{highest_id}, account{a} {
            highest_id++;
            customers.push_back(this);
            } 
        string to_string(void){
            return Person::to_string() + " " + std::to_string(customer_id);
        }
};
int Customer::highest_id {0};
vector<Customer *> Customer::customers{};

void print_cost(void){
    for (auto c : Customer::customers){
        cout << c->to_string() << endl;
    }
}

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
        string to_string(void){
            return Person::to_string() + " " + std::to_string(employee_id);
        }
};
int Employee::highest_id {0};

class Mechanic : public Employee{
    private:
        double hourly_salary, hours;
    public:
        Mechanic(string name, string address) : Employee(name, address) {} 
        string to_string(void){
            return Employee::to_string();
        }
};

class Sales_person : public Employee{
    private:
        double sale, provision;
    public:
    Sales_person(string name, string address) : Employee(name, address) {} 
        string to_string(void){
            return Employee::to_string();
    }
};

class Director : public Employee{
    private:
        string company_car ;
        double monthly_salary;
    public:
    Director(string name, string address) : Employee(name, address) {} 
        string to_string(void){
            return Employee::to_string();
    }
};


int main (void){
    Customer c1("Joe", "Street 8", 4.0);
    //customers.push_back(&c1);
    Customer c2("Jon", "Street 7", 5.0);
    //customers.push_back(&c2);
    Customer c3("Jo", "Street 6", 5.0);
    //customers.push_back(&c3);

    vector<Employee *> employees{};
    Sales_person s1("Anna", "Street 7");  
    employees.push_back(&s1);
    Director d1("John", "Big street 8");
    employees.push_back(&d1);
    Mechanic m1("Matty", "AK 6");
    employees.push_back(&m1); 
    for (int i = 0; i < customers.size(); i++) {
        cout << (customers[i])->to_string() << endl;
    }
    cout << c1 << endl;

    for (int i = 0; i < employees.size(); i++) {
        cout << (employees[i])->to_string() << endl;
    }

    return 0;
}