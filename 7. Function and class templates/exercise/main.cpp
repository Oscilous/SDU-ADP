
#include <iostream>
using namespace std;

#define INT_QUEUE_SIZE 4


class Person
{
    private:
        string name, address;
    public:
        Person(string n, string a) : name{n}, address{a} {} 
        Person() = default;
        string to_string(void){
            return name + " " + address;
        }
};

class IntQueue{
    private:
        int array[INT_QUEUE_SIZE];
        int queue_start, queue_end, actual_size;
    public:
        IntQueue() : queue_start{0}, queue_end{-1}, actual_size{} {}
        void enqueue(int a){
            array[++queue_end == 4 ? 0 : queue_end] = a;
            actual_size++;
        }
        int dequeue(void){
            int temp = queue_start;
            queue_start++;
            if (queue_start == 4) queue_start = 0;
            actual_size--;
            return array[temp];
        }
        void dump(void){
            for(int i = 0; i < INT_QUEUE_SIZE; i++)
                cout << this->array[i] << endl;
            cout << "Start " << queue_start << ", End " << queue_end << ", Real " << actual_size << endl;
        }
};

template<class type, int size>
class Queue{ 
    friend ostream& operator<<(ostream& out, Person c);
    template<class T, int N>
    friend T average(Queue<T,N> &s);
    private:
        type array[size];
        int queue_start{0}, queue_end{-1}, actual_size{0};
    public:
        inline Queue() = default;
        void enqueue(type a){
            array[++queue_end == size ? 0 : queue_end] = a;
            actual_size++;
        }
        type dequeue(void){
            int temp = queue_start;
            queue_start++;
            if (queue_start == size) queue_start = 0;
            actual_size--;
            return array[temp];
        }
        void dump(void){
            for(int i = 0; i < size; i++)
                cout << this->array[i] << endl;
            cout << "Start " << queue_start << ", End " << queue_end << ", Real " << actual_size << endl;
        }
};
ostream& operator<<(ostream& out, Person c)
{
	out << c.to_string();
	return out;
}

template<class T, int N>
T average(Queue<T,N> &s){
    T sum{};
    for(int i=s.queue_start; i<=s.queue_end; i++){
        sum += s.stack_array[i];
    }
    return sum / (s.top);
}

int main (void){
    IntQueue myQueue;
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(2);
    myQueue.dequeue();
    myQueue.dump();
    //Creating a Queue of type double
    Queue<double, 3> doubleQueue;
    doubleQueue.enqueue(1.1);
    doubleQueue.enqueue(2.1);
    doubleQueue.enqueue(3.1);
    doubleQueue.dump();
    //Creating a Queue of type string
    Queue<string, 4> stringQueue;
    stringQueue.enqueue("Joe");
    stringQueue.enqueue("Qoe");
    stringQueue.enqueue("Xoe");
    stringQueue.dump();
    //Creating a Queue of type Person class
    Queue<Person, 3> personQueue;
    Person Joe("Joe","His street");
    Person Toe("Toe", "Her street");
    personQueue.enqueue(Joe);
    personQueue.enqueue(Toe);
    personQueue.dump();
    return 0;
}