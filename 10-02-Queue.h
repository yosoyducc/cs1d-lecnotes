#pragma once

#include <iostream>

using namespace std;

const int SIZE = 10;

class Queue
{
private:
    int items[SIZE];
    int front;
    int rear;

public:
    Queue()
    {
        front = rear = SIZE - 1;
    }
    ~Queue()
    {
        // wow
    }

    void makeEmpty()
    {
        front = rear = SIZE - 1;
    }

    void enqueue(int item)
    {
        rear = (rear + 1) % SIZE;
        items[rear] = item;
    }

    void dequeue(int &item)
    {
        front = (front + 1) % SIZE;
        item = items[front];
    }

    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return (rear + 1) % SIZE == front;
    }
};
