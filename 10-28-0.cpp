/*

A complete tree is where all levels of the binary tree are filled except the
last level which should always have their nodes to the left. If there are
any gaps in the complete tree at the leaves, then it is not complete.

    O
   / \
  O   O
 / \ /
O  O O

^^ - complete

vv - not complete

    O
   / \
  O   O
 / \   \
O   O   O

Heap trees are where parents have greater or lesser value than all children.

A max-heap tree is a binary tree where the parent is larger than all children.
An example:

    (100)
    /   \
 (80)   (90)

The min-heap tree is simply the inverse of this tree. All children of a parent
are larger than the parent.

Heap is used in priority queue.



ARRAY representation

        (99)
       /    \
   (72)      (58)
   /  \      /  \
(61) (55)  (27) (18)

          0
Vector: [ X, 99, 72, 58, 61, 55, 27, 18 ]

left child: 2 * index
right child: 2 * index + 1
parent: index / 2

THIS APPEARS TO BE DIFFERENT than 10-21 notes where root starts at idx 0

Example: Let's Insert 100

     99
    /  \
   72  61
  /
 58

To keep a complete tree, put the 100 left on last row:

     99
    /  \
   72  61
  /  \
 58  100

Obviously this is not a valid heap. So:
[ X, 99, 72, 61, 58, 100 ]

Find the parent! If greater, swap the values!
[ X, 99, 100, 61, 58, 72 ]

Find the parent again! If greater, swap
[ X, 100, 99, 61, 58, 72 ]

Ta-da! Still a valid heap.

    100
    /  \
   99  61
  /  \
 58  72

If we wanted to remove 100?

Find the smallest node (in our case 72)
Place at 100 the number 72
[ X, 72, 99, 61, 58, 72 ]

Delete the smallest node. It is still a complete tree.

     99
    /  \
   72  61
  /
 58

*/

//#include "function.h"

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> heap;

    int leftChild(int index)
    {
        return 2 * index + 1;
    }

    int rightChild(int index)
    {
        return 2 * index + 2;
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    // Index 1 and index 2
    void swap(int i1, int i2)
    {
        int tmp = heap[i1];
        heap[i1] = heap[i2];
        heap[i2] = tmp;
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        int current = heap.size() - 1;

        while (current > 0 && heap[current] > heap[parent(current)])
        {
            swap(current, parent(current));
            current = parent(current);
        }
    }

    void sinkDown(int idx)
    {
        int maxIdx = idx;

        while (true)
        {
            int leftIdx = leftChild(idx);
            int rightIdx = rightChild(idx);

            if (leftIdx < heap.size() && heap[leftIdx] > heap[maxIdx])
                maxIdx = leftIdx;

            if (rightIdx < heap.size() && heap[rightIdx] > heap[maxIdx])
                maxIdx = rightIdx;

            if (maxIdx != idx) {
                swap(idx, maxIdx);
                idx = maxIdx;
            }
            else
            {
                return;
            }
        }
    }

    int remove(int value)
    {
        if (heap.empty())
            return INT_MIN;
    
        int maxValue = heap.front();

        if (heap.size() == 1)
        {
            heap.pop_back();
        }
        else
        {
            heap[0] = heap.back();
            heap.pop_back();
            sinkDown(0);
        }

        return maxValue;
    }
};


int main()
{
    // c
}
