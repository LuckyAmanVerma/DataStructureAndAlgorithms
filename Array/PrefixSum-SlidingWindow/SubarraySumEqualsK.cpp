/*
Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
Example 1:  
Input: nums = [1,1,1], k = 2
Output: 2
Using Brute Force Approach O(n^2)
Using PrefixSum + Map - O(n)

*/

int SubArraySumEqualsK(vector<int> array,int k) {
    int n = array.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = array[0];
    int count = 0;
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + array[i];
    }
    unordered_map<int, int> m; // prefixSum with frequency
    for (int j = 0; j < n; j++) {
        if (prefixSum[j] == k) {
            count++;
        }
        int val = prefixSum[j] - k;
        if (m.find(val) != m.end()) {
            count += m[val];
        }
        if (m.find(prefixSum[j]) == m.end()) {
            m[prefixSum[j]] = 0;
        }
        m[prefixSum[j]] += 1;
    }
    return count;
}
