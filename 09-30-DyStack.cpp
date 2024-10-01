/*

Definitions of dynamic stack class members

*/

#include "09-30-DyStack.h"
#include <iostream>


DyStack::DyStack()
{
    top = nullptr;
}

DyStack::~DyStack()
{
    StackNode *nodePtr = top, *nextNode = nullptr;

    // sequential deletion of objects
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void DyStack::push(int val)
{
    // allocate new object on the heap
    StackNode *newNode = new StackNode;

    // set its value
    newNode->value = val;

    // if empty, set to top
    if (isEmpty())
    {
        top = newNode;
        newNode->next = nullptr;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

void DyStack::pop(int &item)
{
    StackNode *oldNode = top;

    if (isEmpty())
    {
        std::cout << "Stack is empty!\n";
    }
    else
    {
        item = top->value;

        // delete the old node
        top = oldNode->next;
        delete oldNode;
    }
}

bool DyStack::isEmpty()
{
    return top == nullptr;

    // this is how med did it, ugly.
    /*bool status;
    if (!top)
    {
        status = true;
    }
    else
    {
        status = false;
    }
    return status;*/
}
