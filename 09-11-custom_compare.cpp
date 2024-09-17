/*

yes. this is about THAT lab.

so basically I must have erased the second-element-of-a-pair thingy
(i forgot the term :skull:) that was discussed in class on 11.9.

This file serves as an example of that ok.
Given a vector pair of ints it will sort the vector in ascending
order based on the *second* value.
i wrote this in 13 seconds, batteries not included ^.^

*/

//#include <everything>
#include <vector>     // vector. don't know this? you're in trouble
#include <algorithm>  // provides sort()
#include <utility>    // this is where pair comes from
#include <iostream>

using std::pair;
using std::vector;

bool secondCompare(pair<int, int> &, pair<int, int> &);
void printVecPair(vector<pair<int, int>> &);

// objects like classes can be passed to sort to
// define custom comparison logic.
class SecondCompare
{
public:
    // functor that can be passed to sort's comp parameter.
    // it can be used like SecondCompare()
    bool operator()(pair<int, int> &left, pair<int, int> &right) const
    {
        return left.second < right.second;
    }
};

int main(void)
{
    vector<pair<int, int>> pairs = { {1, 2}, {2, 9}, {3, 3}, {4, 1}, {5, -4}, {6, 8}, {7, 0}, {8, 6} };
    printVecPair(pairs);

    // either of the below would work. 
    //std::sort(pairs.begin(), pairs.end(), SecondCompare());
    // we only need to pass the function reference to sort
    std::sort(pairs.begin(), pairs.end(), secondCompare);

    printVecPair(pairs);
}


// this will return the lesser of the two values.
// used in tandem with std::sort it will sort the list in ASCENDING order.
bool secondCompare(pair<int, int> &left, pair<int, int> &right)
{
    return left.second < right.second;
}

void printVecPair(vector<pair<int, int>> &vec)
{
    std::cout << "{ ";

    for (pair<int, int> p : vec)
        std::cout << "(" << p.first << ", " << p.second << "), ";

    std::cout << "}" << std::endl;
}
