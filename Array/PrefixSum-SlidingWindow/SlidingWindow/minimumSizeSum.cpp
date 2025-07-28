/*
Minimum Size Subarray Sum
Input:  nums = [2,3,1,2,4,3], s = 7
Output: 2
*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int size = nums.size();
    int min_size = INT_MAX;
    int i = 0, j = 0, sum = 0;
    while (j < size) {
        sum += nums[j];
        while (sum >= target) {
            min_size = min(min_size, j - i + 1);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    return (min_size == INT_MAX) ? 0 : min_size;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int s = 7;
    cout << "Minimum size subarray sum: " << minSubArrayLen(s, nums) << endl;
    return 0;
}
