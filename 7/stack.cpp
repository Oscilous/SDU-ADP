#include <iostream>
using namespace std;

template<class T, int N>
T average(const T (&array)[N]){
    T sum{};
    for(const T i : array){
        sum += i;
    }
    return sum / N;
}

class Intstack10{
    private:
        int stack_array[10];
        int top;
    public:
        Intstack10(void) : top(-1) {}
        void push(int a){
            stack_array[++top] = a;
        }
        int pop(void){
            return stack_array[top--];
        }
};

template<class ElementType, int size>
class Stack{
    template<class T, int N>
    friend T average(Stack<T , N> &s);
    private:
        ElementType stack_array[size];
        int top;
    public:
        Stack(void) : top(-1) {}
        void push(ElementType a){
            stack_array[++top] = a;
        }
        ElementType pop(void){
            return stack_array[top--];
        }
};

template<class T, int N>
T average(Stack<T,N> &s){
    T sum{};
    for(int i=0; i<=s.top; i++){
        sum += s.stack_array[i];
    }
    return sum / (s.top);
}

int main (void){

    Intstack10 stack;
    stack.push(11);
    stack.push(12);
    cout << stack.pop() << endl;

    Stack<double, 8> myStack;
    myStack.push(11.1);
    myStack.push(12.3);
    cout << "Average: " << average<double>(myStack) << endl;
    return 0;
}