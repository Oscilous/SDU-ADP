#include <iostream>
#include <vector>
#include <functional>

using namespace std;

//First part
void increase(int& sum, int delta){ sum += delta;}

//Second part
class Factor_functor{
    
    int factor;
public:
    Factor_functor(int f) : factor(f) {}
    int operator() (int x) { return x * factor; }
};

int main(void){
    //First part
    //void (*f_ptr) (int&, int) = increase;
    auto f_ptr = increase;
    int a = 4;
    f_ptr(a,6);
    cout << "Result: " << a << endl;

    //Second part
    Factor_functor twice(2), tripple(3), quadruple(4);  
    int b = 3;
    cout << "Twice of a is " << twice(b) << endl;
    cout << "Tripple of a is " << tripple(b) << endl;
    cout << "Quadtruple of a is " << quadruple(b) << endl;
    cout << "Tenfold of a is " << Factor_functor(10)(a) << endl;

    //Lambda expressions
    
    return 0;
}