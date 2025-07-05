/*
Leetcode Two Sum II - Input array is sorted
Problem Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
Time Complexity: O(n)
Input: {2, 7, 11, 15}, target = 9
Output: [1, 2]
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int start=0;
        int end=n-1;
        int sum =0;
        vector<int> result(2);
        while(end>start) {
            sum=numbers[start]+numbers[end];
            if(sum==target) {
               result[0]=start+1;
               result[1]=end+1;
            }
            if(sum<target){
                start+=1;
            }
            else {
                end-=1;
            }
        }
        return result;
    }
};