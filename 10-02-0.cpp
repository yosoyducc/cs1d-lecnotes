/*

Queues and dynamic queues, custom implementation and use.

*/

#include <iostream>
#include "10-02-Queue.h"
#include "10-02-DyQueue.h"

using namespace std;


// === main() =============================================================
//
// ========================================================================
int main()
{
    const int MAX_VALUES = 5;

    DyQueue dq;

    cout << "Enqueuing " << MAX_VALUES << " items\n";
    for (int i = 0; i < MAX_VALUES; dq.enqueue(++i));

    cout << "Printing the values: { ";
    while (!dq.isEmpty())
    {
        int val;
        dq.dequeue(val);
        cout << val << " ";
    }
    cout << "}\n";

    return 0;
}


// === main1() ============================================================
// Old main function.
// ========================================================================
/*int main()
{
    Queue q;

    int item;
    int i{};

    q.makeEmpty();

    cout << "Enter values, or -1 to quit: ";
    while (!q.isFull())
    {
        cout << "Item #" << ++i << ": ";
        cin >> item;

        if (item == -1)
        { break; }

        q.enqueue(item);
    }
    cout << "\n";

    cout << "Here is the queue lol:\n";
    while (!q.isEmpty())
    {
        q.dequeue(item);

        cout << item << " --> ";
    }
    cout << "\n";

    //cout << "\n\n";
    return 0;
}*/