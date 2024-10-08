/*

STL priority queue.
Priority queues share the same idea with maps and sets.
PQs store data elements with an associated priority.

We we add an element to a PQ, its priority determines where
it sits in the queue. The elements with the highest priority
will be popped first, with least priority elements popped last.

How does this differ from map and set?
There's no key-value pairs!

*/


#include <iostream>
#include <queue>

using namespace std;

class Person
{
private:
    string name;
    int age;

    friend ostream &operator<<(ostream &os, const Person &p)
    {
        os << "(" << p.name << ": " << p.age << ")";
        return os;
    }

public:
    Person(): name{"Mort"}, age{0} {};
    Person(string name, int age): name{name}, age{age} {};

    bool operator<(const Person &rhs) const
    {
        // here we can either sort by name or age
        //return this->name < rhs.name;
        return this->age < rhs.age;
    }
};

template<typename T>
void display(priority_queue<T> pq);

void test1();
void test2();

int main(int argc, char *argv[])
{
    void (*funPtr[])() = {
        test1,
        test2
    };

    for (void (*fun)() : funPtr)
    {
        fun();
    }
    return 0;
}


// display template
template<typename T>
void display(priority_queue<T> pq)
{
    cout << "[ ";
    while (!pq.empty())
    {
        T elem = pq.top();
        pq.pop();
        cout << elem << " ";
    }
    cout << "]\n";
}


// test 1 with integer numbers
void test1()
{
    cout << "\n============ Test1 ============\n";

    priority_queue<int> pq;
    for (int i : { 3, 5, 7, 12, 23, 4, 100, 0, 7, 7, 101, 33 })
    {
        pq.push(i);
    }

    cout << "Size is " << pq.size() << "\n";
    cout << "Top: " << pq.top() << "\n";
    display(pq);
    pq.pop();
    display(pq);
}


// priority queue testing with Person class
void test2()
{
    cout << "\n============ Test2 ============\n";

    priority_queue<Person> pq;
    pq.push(Person{"A", 10});
    pq.push(Person{"B", 1});
    pq.push(Person{"C", 14});
    pq.push(Person{"D", 18});
    pq.push(Person{"E", 7});
    pq.push(Person{"F", 2});

    display(pq);
}
