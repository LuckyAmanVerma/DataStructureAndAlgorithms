/*
i=0,1,2,3,4
maxHeap =[1]
maxHeap=[3,1]
maxHeap=[3,1,2]
i=3 , size exceed k=3;maxHeap=[4,3,1,2]
Pop 4, maxHeap=[3,1,2]
i=4 , size exceed k=3;maxHeap=[5,3,1,2]
Pop 5, maxHeap=[3,1,2]
top=3 , 3rd smallest element
Time Complexity: O(n log k) where n is the number of elements in the array.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int kthSmallest(vector<int>& arr, int k) {  // [1,3,2,4,5] k=3
    priority_queue<int> maxHeap;  // Max heap by default in C++  

    for (int i = 0; i < arr.size(); ++i) { //i=0,1,2,3,4
        maxHeap.push(arr[i]);  // Insert element into heap  maxHeap=[5, 4, 3, 2, 1]

        if (maxHeap.size() > k) { //heap size exceeds 
            maxHeap.pop();  // Remove largest if heap exceeds size k
        }
    }

    return maxHeap.top();  // kth smallest is now at the root (top) of the heap
}

int main() {
    vector<int> array={1,3,2,4,5};
    cout<<kthSmallest(array,3);
}
