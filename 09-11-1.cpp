/*

Vectors and deques.

*/

#include <deque>
#include <iostream>
#include <algorithm>
//#include <string>
//#include <utility>
#include <iterator>
#include <vector>

using namespace std;

template<typename T>
void display(const deque<T> &d);
void test1(), test2(), test3(), test4();

int main()
{
    // Somewhere here I must have had it. The sorting algo.
    // Because I've definitely written down every single thing Med wrote.
    // it's gone though. See custom_compare.cpp for custom sorting of pairs.
    /*vector<pair<int, string>> vec;

    vec.push_back({ 1, "Apple" });
    vec.push_back({ 1, "Banana" });
    vec.push_back({ 1, "Cherry" });
    vec.push_back({ 1, "Seth" });

    for (const auto &p : vec)
    {
        cout << "ID: " << p.first << ", Name: " << p.second
            << endl << endl;
    }*/


    // some stuff with vectors
    /*vector<int> list{ 33, 23, 53, 12, 99, 12 };

    // set a capacity of the array
    list.reserve(20);
    cout << "The size of the array is " << list.size() << "\n\n";
    cout << "The capacity of the vector is " << list.capacity() << "\n\n";

    // each time will multiply vector size by 1.5
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    //list.push_back(50);
    //list.push_back(60);

    cout << "The size of the array is " << list.size() << "\n\n";
    cout << "The capacity of the vector is " << list.capacity() << "\n\n";
    cout << list.max_size();  // prints max number of elements, dependent on free ram*/

    // and deques!
    test1();
    test2();
    test3();
}


template <typename T>
void display(const deque<T> &d)
{
    cout << "[ ";
    for (const auto &e : d)
    {
        cout << e << " ";
    }
    cout << "]" << endl;
}

void test1()
{
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    deque<int> dq;

    for (const auto &e : vec)
    {
        if (e % 2 == 0) dq.push_back(e);
        else dq.push_front(e);
    }
    display(dq);
}

void test2()
{
    cout << "====== tezt2==============\n\n";
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    deque<int> dq;

    for (const auto &e : vec)
    {
        dq.push_front(e);
    }
    display(dq);
    dq.clear();

    for (const auto &e : vec)
    {
        dq.push_back(e);
    }
    display(dq);
}

void test3()
{
    cout << "======= test 23 ==============\n";
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    deque<int> dq;

    copy(vec.begin(), vec.end(), front_inserter(dq));
    display(dq);

    copy(vec.begin(), vec.end(), back_inserter(dq));
    display(dq);
}