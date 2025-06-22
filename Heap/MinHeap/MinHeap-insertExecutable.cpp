class Solution {
public:
    int kthSmallest(vector<int>& arr, int k) {
        // Use a max heap of size k
        priority_queue<int> maxHeap;
        for (int i = 0; i < arr.size(); ++i) {
            maxHeap.push(arr[i]);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        // The root of the max heap is the kth smallest element
        return maxHeap.top();
    }
};