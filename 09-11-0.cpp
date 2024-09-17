/*

List manipulation and tests.

*/


#include <iostream>
//#include <vector>
#include <list>
#include <algorithm>
#include <iterator>


using namespace std;

class Person
{
    friend ostream &operator<<(ostream &os, const Person &p);
    string name;
    int age;

public:
    Person() : name{ "Unknown" }, age{ 0 } {}
    Person(string name, int age)
        : name{ name }, age{ age } {}
    bool operator<(const Person& rhs) const
    {
        return this->age < rhs.age;
    }
    bool operator==(const Person& rhs) const
    {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

template<typename T>
void display(const list<T> &l);

void test1(), test2(), test3(), test4(), test5();

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}

void test1()
{
    cout << "Test1==================" << endl;
    list<int> l1{ 1, 2, 3, 4, 5 };
    display(l1);

    list<string> l2;
    l2.push_back("this is the part where I say what the fuck is a kilometer!!?!?!?!?");
    l2.push_front("you are missing your frontal lobe");
    display(l2);

    list<int> l3;
    l3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    display(l3);

    list<int> l4(10, 100);
    display(l4);
}

void test2()
{
    cout << "test2====================\n";

    list<int> l{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    display(l);

    cout << "size " << l.size() << "\n\n";
    cout << "Front of the list: " << l.front() << "\n\n";
    cout << "Back of the list: " << l.back() << "\n\n";

    l.clear();
    display(l);

    cout << "Size is " << l.size() << "\n\n";
}

void test3()
{
    cout << "=== le Teste3 ====================\n";

    list<int> l{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    display(l);

    l.resize(5);
    display(l);

    l.resize(10);
    display(l);

    list<Person> people;
    people.resize(5);
    display(people);
}

void test4()
{
    cout << "=== le Testefour ====================\n";

    list<int> l{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    display(l);

    auto it = find(l.begin(), l.end(), 5);

    if (it != l.end())
    {
        l.insert(it, 100);
    }

    display(l);

    list<int> l2{ 1000, 2000, 3000 };
    l.insert(it, l2.begin(), l2.end());
    display(l2);

    advance(it, -4);
    cout << *it << "\n\n";

    l.erase(it);
    display(l);
}

void test5()
{
    cout << "=== test 5 ====================\n";

    list<Person> data{ {"Larry", 18}, {"Moe", 32}, {"Seth", 50} };

    display(data);

    string name{};
    int age{};

    cout << "Enter a name for the next Person: ";
    getline(cin, name);
    cout << "Enter " << name << "'s age: ";
    cin >> age;

    data.emplace_back(name, age);

    display(data);

    auto it = find(data.begin(), data.end(), Person{ "Moe", 32 });
    
    if (it != data.end())
    {
        data.emplace(it, Person{ "Med", 60 });
    }

    display(data);

    data.sort();

    display(data);
}


// overloading and template.
ostream &operator<<(ostream &os, const Person &p)
{
    os << p.name << ":" << p.age;
    return os;
}

template<typename T>
void display(const list<T> &l)
{
    cout << "[ ";
    for (const auto &elem : l)
    {
        cout << elem << " ";
    }
    cout << "]" << endl;
}
