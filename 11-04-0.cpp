/*

queue

roles = [ 5, 1, 3, 2, 4 ]
output = 33
pq<int, vector<int>, ?> order;

the ? by default uses less<type> which makes the underlying structure a max heap.
to create a min heap, we use greater<type>.

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int findKthLargest(vector<int> &nums, int k);

int main()
{
    vector<int> nums = { 3, 2, 1, 5, 6, 4 };
    int k = 2;

    cout << "The " << k << "th largest element is: " << findKthLargest(nums, k) << "\n\n";
}

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int n : nums)
    {
        minHeap.push(n);
        if (minHeap.size() > k)
            minHeap.pop();
    }

    return minHeap.top();

    // old code from totalCost that I don't think works.
    /*int totalCost{};

    while (minHeap.size() > 1)
    {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        totalCost += first + second;
        minHeap.push(totalCost);
    }*/
}
