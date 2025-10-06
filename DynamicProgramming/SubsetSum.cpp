/*
Subset Sum Problem using Dynamic Programming
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to the given sum.
Return true if there is a subset with sum equal to the given sum, otherwise return false.   
1. Initialization - 0th row and 0th column of dp array is initialized to false, except dp[0][0] which is true.
2. Choice Diagram - If the current element is less than or equal to the current sum,
   we have two choices - include the element or exclude it.
   If the current element is greater than the current sum, we can only exclude it.
   3. Recurrence Relation - The recurrence relation can be defined as:
      dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]] if arr[i-1] <= j
      dp[i][j] = dp[i-1][j] if arr[i-1] > j
      4. Implementation - The implementation can be done using a 2D array or a 1D array.
Input: arr[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True  //There is a subset (4, 5) with sum 9
Time Complexity: O(n*sum)
Space Complexity: O(n*sum)
*/

#include<iostream>
#include<vector>
using namespace std;

bool subsetSum(vector<int> &arr,int sum) {
    int n=arr.size();
    //initialization
    vector<vector<bool>> dp(n+1,vector(sum+1,false));
    for(int i = 0; i < n+1; i++) {
        dp[i][0] = true;
    }
    for(int j = 1; j < sum+1; j++) {
        dp[0][j] = false;
    }

    for(int i=1;i<n+1;i++) {
        for(int j=1;j<sum+1;j++) {
            if(arr[i-1]<=j) {
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 99;
    if(subsetSum(arr,sum)) {
        cout<<"True"<<endl;
    }
    else {
        cout<<"False"<<endl;
    }
    return 0;
}