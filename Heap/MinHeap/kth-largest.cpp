/*
Find the kth largest element in an array using a min heap.
Time Complexity: O(n log k) where n is the number of elements in the array.
*/
#include <vector>
#include <queue>
using namespace std;

int kthLargest(vector<int>& arr, int k) {  // [1,3,2,4,5] k=3
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min heap

    for (int i = 0; i < arr.size(); ++i) {
        minHeap.push(arr[i]);
        if (minHeap.size() > k) {
            minHeap.pop();  // Remove smallest if heap exceeds size k
        }
    }
    return minHeap.top();  // kth largest is now at the root (top) of the heap
}
