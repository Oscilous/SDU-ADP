
#include <iostream>
#include <algorithm>
#include <map>
    
using namespace std;

struct Print
{
    void operator()(pair<string, int> element){
        cout << element.first << " " << element.second << endl;
    }
};

void print_regular(pair<string, int> element){
    cout << element.first <<" "<< element.second << endl;
}

//Regular function
//auto compare(pair<string,int> a, pair<string,int> b) {
//             return a.second < b.second;
//}

//Functor
struct Compare{
    bool operator()(pair<string,int> a, pair<string,int> b){
        return a.second < b.second;
    }
}compare;

class Customer_credit_register{
private:
    map<string, int> credit_maximums;
public:
    int get_creditMax(string s){
        if (credit_maximums.find(s) != credit_maximums.end())
            return credit_maximums[s];
        return -1;
    }
    void register_customer(string s, int c){
        if (credit_maximums.find(s) == credit_maximums.end())
            credit_maximums.insert(pair{s, c});
    }
    void set_creditMax(string s, int c){
        if (credit_maximums.find(s) != credit_maximums.end()){
            credit_maximums[s] = c;
        }
    }
    void print_credit(string s){
        if (credit_maximums.find(s) != credit_maximums.end()){
            cout << s << " " << credit_maximums.at(s) << endl;
        }
    }
    int sum_of_creditMaxes(void){
        int sum = 0;
        for(const auto& [key, value] : credit_maximums){
            sum += value;
        }
        return sum;
    }
    void clear_all_creditMaxes(void){
        for(const auto& [key, value] : credit_maximums){
            credit_maximums.at(key) = 0;
        }
    }
    void print_all(void){
        //Lambda variation
        //auto print =  [](pair<string, int> element){cout<< element.first <<" "<< element.second << endl;};
        //for_each(credit_maximums.cbegin(), credit_maximums.cend(), print);
 
        //Function object
        //for_each(credit_maximums.cbegin(), credit_maximums.cend(), Print());

        //Regular function
        for_each(credit_maximums.cbegin(), credit_maximums.cend(), print_regular);
    }
    int get_creditMax_maximum(void){
        //Lamda
        //auto compare = [](pair<string,int> a, pair<string,int> b) {
        //     return a.second < b.second; };
        pair<string, int> max_pair = *max_element(credit_maximums.begin(), credit_maximums.end(), compare); 
        return max_pair.second;
    }
};

int main(void){
    
    Customer_credit_register myCustomers;

    myCustomers.register_customer("Joe", 50);
    myCustomers.set_creditMax("Joe", 400);
    myCustomers.print_credit("Joe");
    cout << boolalpha;
    myCustomers.register_customer("Jo", 1);
    cout << "Total maximums: " << myCustomers.sum_of_creditMaxes() << endl;
    myCustomers.clear_all_creditMaxes();
    cout << "Total maximums: " << myCustomers.sum_of_creditMaxes() << endl;
    
    myCustomers.register_customer("Bo", 500);
    myCustomers.print_all();
    cout << "Highest maximum is " << myCustomers.get_creditMax_maximum();
    return 0;
}