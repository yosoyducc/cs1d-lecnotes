/*

Stacks.
This uses a custom implementation, in 09-30-Stack.h.

*/


#include <iostream>
#include "09-30-Stack.h"

const int SIZE = 10;

int main()
{
    int item{};
    // The declaration for the template stack is very similar to that of vectors, etc...
    Stack<int, SIZE> stack;

    //stack.makeEmpty();

    std::cout << "The contents of the stack: ";
    while (!stack.isEmpty())
    {
        stack.pop(item);
        std::cout << item << " --> ";
    }
    std::cout << "Null\n";

    std::cout << "Please enter " << SIZE << " integers to be pushed to the stack.\n";
    for (int i = 0; !stack.isFull(); ++i)
    {
        std::cout << "Item #" << i << ": ";
        /*std::cin >> item;
        stack.push(item);*/
        stack.push(i);
    }

    std::cout << "\nDisplay the values from the stack:\n";
    while (!stack.isEmpty())
    {
        stack.pop(item);
        std::cout << item << " --> ";
    }
    std::cout << "Null" << std::endl;
}
