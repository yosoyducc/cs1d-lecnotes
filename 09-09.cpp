/*

Vectors, algos, iterators, and simple manipulation.
Some code is commented out.

*/

//#include <iomanip>
#include <iostream>
//#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 100
#define MAX(a, b) ((a > b) ? a : b)
#define COUT_TW (cout << "\n\n")

void doubleList(vector<int> &list);
void printList(const vector<int> &list);

typedef vector<int>::iterator it;

int main()
{
    // thing 2
    /*vector<int> b2 = { -2, 4, 3, 55, 6, -78, 8, -10 };

    vector<int>::iterator it;
    ostream_iterator<int> out(cout, " ");

    copy(b2.begin(), b2.end(), out);

    sort(b2.begin(), b2.end());
    cout << "\n\n";

    copy(b2.begin(), b2.end(), out);
    cout << "\n\n";

    copy(b2.rbegin(), b2.rend(), out);
    cout << "\n\n";

    cout << b2.at(20) << "\n"; */
    
    // thing 3 //
    //vector<int> list{ 13, 10, -9, 88, -30, 53, 18, 33, 8 };
    vector<int> list{ 33, 23, 53, 12, 99, 12 };
    sort(list.begin(), list.end());

    for (auto it = list.begin(); it != list.end(); it++)
    {
        cout << *it << '\t';
    }

    printList(list);
    COUT_TW;

    // index of the first element greater than or equal to 20
    // index of the first element less than or equal to 20
    it low = lower_bound(list.begin(), list.end(), 20);
    it high = upper_bound(list.begin(), list.end(), 20);

    cout << "Index GE 20: " << low - list.begin() << "\n";
    cout << "Index LE 20: " << high - list.begin() << "\n";

    // this causes a compile error...
    //for_each(list.begin(), list.end(), doubleList);

    COUT_TW;

    printList(list);
    COUT_TW;
    //doubleList(list);
    //printList(list);
    //COUT_TW;

    if (binary_search(list.begin(), list.end(), 53))
    {
        cout << "53 is found\n";
    }
    else
    {
        cout << "53 not found\n";
    }

    return 0;
}

void doubleList(vector<int> &list)
{
    for (auto &p : list)
    {
        p = p * 2;
    }
}

void printList(const vector<int> &list)
{
    for (auto p : list)
    {
        cout << p << '\t';
    }
}

// using templates...
/*
template<typename T, typename Y>
T calcSquare(T num, Y num1)
{
    return num*num;
}
*/