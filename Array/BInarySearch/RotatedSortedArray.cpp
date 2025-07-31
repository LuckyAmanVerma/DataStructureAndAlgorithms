/*
Find Minimum in Rotated Sorted Array
This code finds the minimum element in a rotated sorted array.
Using Binary Search
Input: [4,5,6,7,0,1,2]
*/

#include <iostream>
#include <vector>
using namespace std;

int findMinInRotatedArray(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

//     while (left < right) {
//         int mid = left + (right - left) / 2;

//         if (nums[mid] > nums[right]) {
//             left = mid + 1;
//         } else {
//             right = mid;
//         }
//     }

//     return nums[left]; // The minimum element is at the position right + 1
// }

int main() {
    vector<int> data = {4, 5, 6, 7, 1, 2};
    int minElement = findMinInRotatedArray(data);
    cout << "The minimum element in the rotated sorted array is: " << minElement << endl;
    return 0;
}