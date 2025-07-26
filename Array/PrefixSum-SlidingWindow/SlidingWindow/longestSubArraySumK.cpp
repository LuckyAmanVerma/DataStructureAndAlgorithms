/*
Example: Given an array of integers and a target sum K values are positive, find the length of the longest subarray that sums to K.
Using Sliding Window Technique - O(n)
Input: [1,2,3,4,5], K = 9
Output: 3 (subarray [2,3,4] or [4,5])
If no such subarray exists, return 0.
*/

#include <vector>
#include<iostream>
using namespace std;

int longestSubArraySumK(vector<int> array, int k) {cd 
    int n = array.size();
    int i = 0, j = 0, sum = 0, ans = 0;

    while (j < n) {
        if (sum < k) {
            sum += array[j++];
        }
        else if (sum == k) {
            ans = max(ans, j - i);
            sum += array[j++];
        }
        else {
            sum -= array[i++];
        }
    }

    // Final window check when j == n
    if (sum == k) {
        ans = max(ans, j - i);
    }

    return ans;
}

int main(){
    vector<int> array={1,1,1};
    cout<<longestSubArraySumK(array,2);
}