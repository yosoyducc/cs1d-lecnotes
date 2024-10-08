#pragma once

#include <iostream>

/*

Remember that queues are first-in, first-out.
So the first element that we add to the queue is going to be the first one
that we get back when we pop it, and the last element will be last.

*/

class DyQueue
{
private:
    struct QueueNode
    {
        int value;
        QueueNode *next;
    };
    QueueNode *front, *rear;
    int numItems;

public:
    DyQueue() : front(nullptr), rear(nullptr), numItems(0) {}
    ~DyQueue() { clear(); }

    // Add an element to the end of the queue.
    void enqueue(int num)
    {
        QueueNode *newNode = new QueueNode;
        newNode->value = num;
        newNode->next = nullptr;

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        ++numItems;
    }

    // Pop the first element in line.
    void dequeue(int &num)
    {
        if (isEmpty())
        {
            std::cout << "Queue empty\n";
        }
        else
        {
            QueueNode *aux = front;
            num = front->value;
            front = front->next;
            delete aux;
            --numItems;
        }
    }

    bool isEmpty() const
    {
        return numItems == 0;
    }

    void clear()
    {
        int val;
        while (!isEmpty())
        {
            dequeue(val);
        }
    }
};