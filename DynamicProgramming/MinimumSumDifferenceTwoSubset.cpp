/*
Minimum Sum Difference of Two Subsets using Dynamic Programming
Given a set of integers, partition the set into two subsets such that the absolute difference between their sums is minimum.
Input: arr[] = {1, 6, 11, 5}
Output: 1  //Subset1 = {1, 5, 6}, sum = 12
           //Subset2 = {11}, sum = 11
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int minimumSubsetSumDifference(const vector<int>& arr) {
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0);

    // DP table: dp[i][j] = true if sum j is possible with first i elements
    vector<vector<bool>> dp(n + 1, vector<bool>(total + 1, false));
    for (int i = 0; i <= n; i++) dp[i][0] = true; // sum 0 is always possible

    // DP fill
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= total; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // Find minimum difference
    int diff = INT_MAX;
    for (int j = 0; j <= total / 2; j++) {
        if (dp[n][j]) {
            diff = min(diff, total - 2 * j);
        }
    }
    return diff;
}

int main() {
    vector<int> arr = {1, 6, 11, 5};
    cout << "Minimum subset sum difference is " << minimumSubsetSumDifference(arr) << endl;
    return 0;
}
