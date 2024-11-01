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

#include <climits>  // INT_MIN
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
    void printHeap()
    {
        cout << "\n[";
        for (size_t i = 0; i < heap.size(); ++i)
        {
            cout << heap[i];
            if (i < heap.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    const vector<int> &getHeap() const
    {
        return heap;
    }

    void insert(int value)
    {
        // Add the new value at the end of the heap array.
        // This might temporarily break the heap's property.
        heap.push_back(value);
        // Set 'current' to the index of the newly added element
        int current = heap.size() - 1;

        // Start a loop to restore the heap property. This loop
        // continues as long as 'current' isn't the root (index 0)
        // and the current element is larger than its parent. This
        // is essential for maintaining the max heap property.
        while (current > 0 && heap[current] > heap[parent(current)])
        {
            // Swap the current element with its parent if the
            // current element is larger. This is a step towards
            // restoring the max heap property bu ensuring that a 
            // parent node is always larger than its children.
            swap(current, parent(current));
            // Move up the tree by setting 'current to the index
            // of the parent node. This step is crucial for the
            // iterative comparison of the newly inserted value
            // with its ancestors, ensuring the heap's integrity.
            current = parent(current);
        }
    }

    void sinkDown(int idx)
    {
        // Initialize maxIndex with the current index. This variable
        // will be used to find the largest of the current node and
        // its children.
        int maxIdx = idx;
        // Enter a loop that continues indefinitely until explicitly
        // broken out of. The purpose is to restore heap property.
        while (true)
        {
            // Calclulate the indices of the left and right children
            // of the current node.
            int leftIdx = leftChild(idx);
            int rightIdx = rightChild(idx);

            // If the left child exists and is greater than the
            // current node, update maxIndex to leftIndex. This
            // step identifies the larger of the two children.
            if (leftIdx < heap.size() && heap[leftIdx] > heap[maxIdx])
                maxIdx = leftIdx;

            // Perform a similar check for the right child. If the
            // right child exists and is greater than the current
            // max (either the parent or left child), update maxIndex
            // to rightIndex. This ensures maxIndex points to the
            // largest of the parent and its two children.
            if (rightIdx < heap.size() && heap[rightIdx] > heap[maxIdx])
                maxIdx = rightIdx;

            // If maxIndex has been updated, indicating that either
            // the left or right child is larger than the parent,
            // swap the parent with this larger child. This is a
            // key step in restoring the max heap property by
            // ensuring parents are larger than their children.
            if (maxIdx != idx) {
                swap(idx, maxIdx);
                // Update index to maxIndex for the next iteration.
                // This move down the tree, continuing to adjust
                // the heap as needed.
                idx = maxIdx;
            }
            else
            {
                // If maxIndex has not changed, the heap property
                // has been restored for this subtree, and the loop
                // can be exited.
                return;
            }
        }
    }

    /* NOTICE: in the in-class lecture there was argument `int value`
     * here, but it went unused in this function anyway. */
    int remove()
    {
        // Check if the heap is empty. If it is,
        // return the minimum integer value as an
        // indication of an underflow condition.
        if (heap.empty())
            return INT_MIN;
    
        // Store the value at the root of the heap.
        // This is the maximum value in a max heap.
        int maxValue = heap.front();

        // If the heap only contains one element,
        // simply remove it and return its value.
        if (heap.size() == 1)
        {
            heap.pop_back();
        }
        else
        {
            // Replace the root of the heap with the last element
            // in the heap. This action maintains the completeness
            // of the binary tree but may violate the heap property.
            heap[0] = heap.back();
            // Remove the last element as it's now moved to the root.
            heap.pop_back();
            // Call sinkDown to restore the max heap property starting
            // from the root. This method adjusts the position of the
            // new root by moving it down the tree until the heap property
            // is restored.
            sinkDown(0);
        }

        // Return the maximum value that was removed from the heap.
        return maxValue;
    }
};


void test();

int main()
{
    test();

    return 0;
}

void test()
{
    Heap heap;

    // Insert values into the heap
    vector<int> values = { 10, 20, 30, 5, 15, 25, 35 };
    cout << "Inserting values: ";
    for (int v : values)
    {
        cout << v << " ";
        heap.insert(v);
    }
    cout << "\nInitial Heap: ";
    heap.printHeap();

    // Remove values from the heap and test after each removal
    while (!heap.getHeap().empty())
    {
        int removedValue = heap.remove();
        cout << "\nRemoved Value: " << removedValue;
        cout << "\nHeap after removal: ";
        heap.printHeap();

        // Verify max heap property
        const vector<int> &currentHeap = heap.getHeap();
        bool isValidMaxHeap = true;
        for (size_t i = 0; i < currentHeap.size(); ++i)
        {
            int left = 2 * i + 1;  // Calculating left child index
            int right = 2 * i + 2;  // Calculating right child index
            if (left < currentHeap.size() && currentHeap[i] < currentHeap[left])
            {
                isValidMaxHeap = false;
                break;
            }
            if (right < currentHeap.size() && currentHeap[i] < currentHeap[right])
            {
                isValidMaxHeap = false;
                break;
            }
        }

        cout << "\nMax Heap Property Valid? " << (isValidMaxHeap ? "Yes" : "No") << "\n";
    }

    // Check if heap is empty at the end
    cout << "\nFinal Heap (Should be empty): ";
    heap.printHeap();
}
