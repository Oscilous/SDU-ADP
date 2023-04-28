
#include <iostream>
#include <vector>
#include <functional>
    
using namespace std;

//Function pointers
void sum(int &a, int i) { a += i;}
void subtract(int &a, int i) { a -= i;}
void multiply(int &a, int i) { a *= i;}
void divide(int &a, int i) { a /= i;}


template <typename Operation_functor>
void calculate(int& acc, int inp) {
  Operation_functor()(acc, inp);
}

class Sum_functor{
public:
    void operator() (int& acc, int inp){
        acc += inp;
    }
};

class Subtract_functor{
public:
    void operator() (int& acc, int inp){
        acc -= inp;
    }
};

class Multiply_functor{
public:
    void operator() (int& acc, int inp){
        acc *= inp;
    }
};

class Divide_functor{
public:
    void operator() (int& acc, int inp){
        acc /= inp;
    }
};

int main(void){
    int accumalator = 0;
    int input;
    int action;
    auto f_ptr = divide;
    cout << "Accumalator = " << accumalator << endl;
    cout << "Please insert a input: ";
    cin >> input;
    cout << endl << "Please chose the mathematical calculation (+ - * /) :";
    cin >> action;
    cout << endl;

    //A
    switch (action)
    {
    case 0:
        f_ptr = sum;
        break;
    case 1:
        f_ptr = subtract;
        break;
    case 2:
        f_ptr = multiply;
        break;
    case 3:
        f_ptr = divide; 
    default:
        break;
    }
    f_ptr(accumalator, input);
    cout << "Result: " << accumalator << endl << endl;
    //B
    cout << endl << "Please chose the mathematical calculation (+ - * /) :";
    cin >> action;
    cout << endl;
    vector<void (*)(int&,int)> operations {sum, subtract, multiply, divide};
    f_ptr = operations[action];
    f_ptr(accumalator, input);
    cout << "Result: " << accumalator << endl << endl;

    //C
    cout << endl << "Please chose the mathematical calculation (+ - * /) :";
    cin >> action;
    cout << endl;
    
    switch (action){
    case 0:
        calculate<Sum_functor>(accumalator, input);
        break;
    case 1:
        calculate<Subtract_functor>(accumalator, input);
        break;
    case 2:
        calculate<Multiply_functor>(accumalator, input);
        break;
    case 3:
        calculate<Divide_functor>(accumalator, input);
        break;
    default:
        break;
    }
    
    cout << "Result: " << accumalator << endl << endl;

    //D

    cout << endl << "Please chose the mathematical calculation (+ - * /) :";
    cin >> action;
    cout << endl;
    auto multiply =  [] (int& a, int i) { a *= i;} ; //Named lamda
    vector<function<void (int&,int)>> wrapper{sum,[] (int& a, int i) { a -= i;}, multiply, calculate<Divide_functor>};
    auto w_ptr = wrapper[action];
    w_ptr(accumalator, input);
    cout << "Result: " << accumalator << endl << endl;

    return 0;
}