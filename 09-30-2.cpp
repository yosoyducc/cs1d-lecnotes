/*

Example usage of STL stacks.

*/


#include <iostream>
#include <stack>

// do not use namespace std.
using namespace std;

int main()
{
    stack<int> inStack;

    inStack.push(7);
    inStack.push(70);
    inStack.push(79);
    inStack.push(89);
    inStack.push(20);

    cout << inStack.size() << "\n\n";

    while (!inStack.empty())
    {
        cout << inStack.top() << " --> ";
        inStack.pop();
    }
    cout << "Null\n";
}