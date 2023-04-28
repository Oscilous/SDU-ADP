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
    cout << "Result: " << a << endl << endl;

    //Second part
    Factor_functor twice(2), tripple(3), quadruple(4);  
    int b = 3;
    int twenty = 20;
    cout << "Twice of b is " << twice(b) << endl;
    cout << "Tripple of b is " << tripple(b) << endl;
    cout << "Quadtruple of b is " << quadruple(b) << endl;
    cout << "Tenfold of b is " << Factor_functor(10)(a) << endl << endl;
    //Lambda expressions 
    int fifty = 50;
    auto fiftyfold =  [fifty] (int x) { return x * fifty;} ; //Named lamda
    cout << "Twentyfold of b is " << [twenty] (int x) { return x * twenty;}(b) << endl;
    cout << "Fiftyfold of b is " << fiftyfold(b) << endl;
    return 0;
}