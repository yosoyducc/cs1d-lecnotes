/*

STL sets.

What are sets?
Sets are a container that holds sorted values (ascending) and contain only unique elements.

Med's code uses namespace std. This doesn't.

*/


#include <iostream>
#include <set>


// Custom object for use in set.
class Person
{
private:
    friend std::ostream &operator<<(std::ostream &os, Person const &p);

    std::string name;
    int age;

public:
    // When creating a custom object that will be used as a set,
    // we need to overload operator to define how to sort the object.
    bool operator<(Person const &rhs) const
    {
        return this->age < rhs.age;
        // we can alternatively compare names
        //return this->name < rhs.name;
    }
    Person() : name{"Crazy Med"}, age{0} {}
    Person(std::string name, int age) : name{name}, age{age} {}
};

template<typename T>
void display(std::set<T> const &l);

// test functions
int const NO_FUN = 4;
void test1();
void test2();
void test3();
void test4();


// === main ===============================================================
//
// ========================================================================
int main()
{
    // function pointers, med didn't use this. it won't be on the quiz
    void (*fun[NO_FUN])(void) = {
        test1, test2, test3, test4
    };

    for (int i = 0; i < sizeof(fun)/sizeof(void *); ++i)
    {
        fun[i]();
    }
}

// === << =================================================================
//
// ========================================================================
std::ostream &operator<<(std::ostream &os, Person const &p)
{
    os << p.name << ": " << p.age;
    return os;
}

// === display ============================================================
//
// ========================================================================
template<typename T>
void display(std::set<T> const &l)
{
    std::cout << "[ ";
    for (auto const &e : l)
    {
        std::cout << e << " ";
    }
    std::cout << "]\n";
}

// just some print function thingy
static inline void pts(int i)
{
    std::cout << "\n========== Test " << i << " ==========\n";
}


// === test1 ==============================================================
// Demo of set of ints.
// ========================================================================
void test1(void)
{
    pts(1);

    std::set<int> s1{ 1, 9, 8, 3, 0, 1, 3 };

    display(s1);

    s1 = { 2, 32, 36, 98, 0, 1, 3 };

    display(s1);

    s1.insert(4);
    s1.insert(10);

    display(s1);

    std::string const FOUND = "1 is found on the set\n\n";
    std::string const NOT_FOUND = "1 is NOT found on the set\n\n";
    // There are two ways to check if there is an element in the set.
    // One way is via count that doesn't use an iterator. Med says this
    // way is cheaper but does it really matter so much???
    std::cout << (s1.count(1) ? FOUND : NOT_FOUND);  // remember ternary operator has lower precedence than <<
    // med used an if else clause for both of these.

    // Another way is using the iterator.
    std::set<int>::iterator it = s1.find(1);
    // auto it = s1.find(1);
    std::cout << (it != s1.end() ? FOUND : NOT_FOUND);

    // delete every value
    s1.clear();
    display(s1);
}

// === test2 ==============================================================
// Using set with other object types (Person class def'd above)
// ========================================================================
void test2(void)
{
    pts(2);

    // basically a pair of name and associated age. but not really i think
    std::set<Person> people{{"Larry", 1}, {"Tom", 22}, {"Joe", 12}};

    display(people);

    people.emplace("Larry", 13);
    display(people);

    // This will not work because there is a conflicting age already in the set.
    people.emplace("Med", 22);
    display(people);

    // remove a specific item in the set
    auto it = people.find(Person{"Tom", 22});
    if (it != people.end())
        people.erase(it);

    display(people);

    // As demonstration, this doesn't care about what the string is.
    // The overloaded operator < only works for the int value.
    it = people.find(Person{"$$$$", 12});
    if (it != people.end())  // this will be taken
        people.erase(it);

    display(people);
}


// === test3 ==============================================================
// idk with strings?? med deleted this
// ========================================================================
void test3(void)
{
    pts(3);

    std::set<std::string> s{"A", "D", "C", "B"};

    display(s);

    auto result = s.insert("F");
    display(s);
}


// === test4 ==============================================================
// unused
// ========================================================================
void test4(void)
{
    pts(4);
}
