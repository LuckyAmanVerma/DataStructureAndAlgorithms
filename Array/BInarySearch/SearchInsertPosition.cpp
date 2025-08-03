/*
Input: nums = [1,3,5,6], target = 2
Output: 1
Explanation: 2 would be inserted before 3 at index 1.

Input: nums = [1,3,5,6], target = 7
Output: 4
Explanation: 7 would be appended at the end, index 4.

// https://leetcode.com/problems/search-insert-position/
// Time Complexity: O(log n)
*/

#include <iostream>
#include <vector>
using namespace std;
//optimized one 

void searchInsert(vector<int> nums,int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
            cout << "Element found at index: " << mid << endl;
        else if (nums[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    cout<< "Element not found, it can be inserted at index: " << start << endl;
    cout<<"end "<<end;
    
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 7;
    searchInsert(nums, target);
    
    // target = 7;
    // searchInsert(nums, target);
    
    return 0;
}