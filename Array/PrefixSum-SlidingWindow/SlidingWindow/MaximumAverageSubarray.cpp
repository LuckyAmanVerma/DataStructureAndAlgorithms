/*
description: Given an integer array nums and an integer k, return the maximum average value of a subarray of length k
Input: nums = [1,12,-5,-6,50,3], k = 4 
Output: 12.75
Using PrefixSum + Sliding Window - O(n)
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSum = INT_MIN;
        vector<int> prefixSum(n + 1, 0); // One extra for easier window sum
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        for (int i = 0; i <= n - k; i++) {
            int current = prefixSum[i + k] - prefixSum[i];
            if (current > maxSum) {
                maxSum = current;
            }
        }
        return (double)maxSum / k;
    }


    /*Sliding Window approach (O(n) time, O(1) space)    [1,12,-5,-6,50,3], k = 4
    nums = [1, 2, 3, 4, 5], k = 3
        Start:
        Window: [1, 2, 3] → sum = 6

        Next:
        Window: [2, 3, 4]
        → subtract 1, add 4 → sum = 6 – 1 + 4 = 9

        Next:
        Window: [3, 4, 5]
        → subtract 2, add 5 → sum = 9 – 2 + 5 = 12

        ✅ Max sum = 12
    */
    double findMaxAverageSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int maxSum = sum;
        for (int i = k; i < n; i++) {
            sum = sum - nums[i - k] + nums[i]; //important logic , subtract the sliding left element and add the new right element
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
        return (double)maxSum / k;
    }
};