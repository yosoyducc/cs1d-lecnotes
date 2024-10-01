#pragma once

// We can use templates to use custom data types here!
template<class T, int SIZE>
class Stack
{
private:
    T items[SIZE];
    int top;

public:
    Stack() { top = -1; }
    ~Stack() {}

    void makeEmpty()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == SIZE - 1;
    }

    void push(T item)
    {
        items[++top] = item;
    }

    void pop(T &item)
    {
        item = items[top--];
    }
};
