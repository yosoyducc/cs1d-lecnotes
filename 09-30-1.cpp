/*

Dynamic Stacks example usage.

*/


#include <iostream>
#include "09-30-DyStack.h"


int main()
{
    int value;

    DyStack stack;

    std::cout << "Pushing values...\n";
    stack.push(5);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(69);
    stack.push(77);

    std::cout << "Popping...\n";

    while (!stack.isEmpty())
    {
        stack.pop(value);
        std::cout << value << "\n";
    }

    std::cout << "Attempting to pop again. lol\n";
    stack.pop(value);
}