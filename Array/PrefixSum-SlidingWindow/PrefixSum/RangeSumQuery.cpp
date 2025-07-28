/*
Range Sum Query : Given an array of integers and two indices L and R, find the sum of elements between L and R (inclusive).
Using Prefix Sum Array:
1. Create a prefix sum array where each element at index i contains the sum of elements from the start of the array to index i.
2. The sum of elements between indices L and R can be calculated as:
   sum(L, R) = prefix[R] - prefix[L-1] (if L > 0)
   sum(0, R) = prefix[R] (if L == 0)
Time Complexity: O(n) for creating the prefix sum array, O(1) for each query.
Space Complexity: O(n) for the prefix sum array.
Input:
nums = [3, 1, 4, 1, 5, 9]
queries = [(0,2), (2,4), (1,5)]
outputs → [3+1+4=8, 4+1+5=10, 1+4+1+5+9=20]
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> rangeSumQuery(const vector<int>& nums,const vector<vector<int>>& queries){
 int asize =nums.size();
 vector<int> prefixSum(asize,nums[0]);
 vector<int> ans;
 for(int i=1;i<asize;i++){
    prefixSum[i]=prefixSum[i-1]+nums[i];
 }

 for(int i=0;i<queries.size();i++){
    int L = queries[i][0];
    int R = queries[i][1];
    int rangeSum = prefixSum[R] -(L==0?0:prefixSum[L-1]);
    ans.push_back(rangeSum);
 }
 return ans;
}

int main(){
    vector<int> nums = {3, 1, 4, 1, 5, 9};
    vector<vector<int>> queries = {{0, 2}, {2, 4}, {1, 5}};
    vector<int> result = rangeSumQuery(nums, queries);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}