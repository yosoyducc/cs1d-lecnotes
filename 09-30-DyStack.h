#pragma once

class DyStack
{
private:
    // single object on stack structure
    struct StackNode
    {
        int value;
        StackNode *next;
    };

    StackNode *top;

public:
    DyStack();
    ~DyStack();

    void push(int);
    void pop(int &);
    bool isEmpty();
};
