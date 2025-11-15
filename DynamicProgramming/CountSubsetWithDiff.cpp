/*
Count number of subset with given difference using Dynamic Programming
Given an array arr[] and a difference diff, count the number of subsets of arr[] such that the difference between the sum of elements in the two subsets is equal to diff.
Input: arr[] = {1, 1, 2, 3}, diff = 1
Output: 2
The subsets are 

1. {1, 1, 2} and {3}
2. {1, 2} and {1, 3}

target sum problem also based on same concept
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int countSubset(vector<int> &arr,int target) {
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector(target+1,0));
    for(int i = 0; i < n+1; i++) {
        dp[i][0] = 1;
    }

    for(int i=1;i<n+1;i++) {
        for(int j=1;j<target+1;j++) {
            if(arr[i-1]<=j) {
                dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][target];

}

int countSubsetWithDiff(vector<int> &arr,int target) {
    int n=arr.size();
    int sumOfArray=accumulate(arr.begin(),arr.end(),0);
    int sum = (target+sumOfArray)/2;
    if ((target + sumOfArray) % 2 != 0) return 0;
    return countSubset(arr,sum);
}

int main() {
    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;
    cout << "Count of subsets with given difference is " << countSubsetWithDiff(arr, diff) << endl;
    return 0;
}


