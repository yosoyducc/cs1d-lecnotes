/*

Example program that parses strings on whitespace.
This is a demo to show that stringstream acts much like cin.

*/


#include <iostream>
#include <sstream>
#include <vector>

using namespace std;



// === main() =============================================================
// example splitting string using delimiter ','
// ========================================================================
int main()
{
    string line = "10 20 30 40 50";
    stringstream ss(line);

    int number{};
    vector<int> numbers;

    while (ss >> number)
    {
        numbers.push_back(number);
    }

    cout << "Values from the vec: ";
    for (auto n : numbers)
    {
        cout << n << " ";
    }
    cout << endl;
}

// === main_old2() =============================================================
// example splitting string using delimiter ','
// ========================================================================
int main_old2()
{
    string line = "Apple, Banana, Orange, Grape";
    stringstream ss(line);

    string word{};

    while (getline(ss, word, ','))
    {
        cout << word << "\n";
    }

    return 0;
}


// === main_old1() ========================================================
// example putting variables in
// ========================================================================
int main_old1()
{
    string line = "123 45.67 Hello";
    stringstream ss(line);

    int num{};
    double num1{};
    // med said to name it whateverYouWant
    string whateverYouWant{};

    ss >> num >> num1 >> whateverYouWant;

    cout << "Integer " << num << "\n\n";
    cout << "Double " << num1 << "\n\n";
    cout << "WhateverYouWant " << whateverYouWant << "\n\n";

    return 0;
}
