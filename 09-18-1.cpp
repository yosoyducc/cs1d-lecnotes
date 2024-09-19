/*

Continuation of STL sets.

Here we use functors, which is an object of a class that can be called as a function.

Med's code uses namespace std. This doesn't.

*/


#include <iostream>
#include <set>


// no need to use typedef here. old habit from c
// while I'm still here this can't be anonymous if using constructor
typedef struct Person
{
    std::string name;
    int age;

    Person(std::string name, int age) : name{name}, age{age} {}
} Person;


// functor object.
typedef struct CompareByName
{
    // The comparison object must be invocable as const
    bool operator()(Person const &lhs, Person const &rhs) const
    {
        return lhs.name < rhs.name;
    }
} CompareByName;


// === main ===============================================================
//
// ========================================================================
int main()
{
    std::set<Person, CompareByName> people;

    people.emplace("Ivan", 12);
    people.emplace("Andrej", 15);
    people.emplace("Milica", 32);

    for (auto const &p : people)
    {
        std::cout << p.name << ": " << p.age << "\n";
    }

    return 0;
}
