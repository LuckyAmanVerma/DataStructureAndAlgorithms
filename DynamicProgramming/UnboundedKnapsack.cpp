/*
Knapspack using Top Down Dynamic Programming approach
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

1. Initialization - 0th row and 0th column of dp array is initialized to 0 or -1.
2. Choice Diagram - If weight of the nth item is less than or equal to W,
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Top-down (Tabulation) Dynamic Programming approach
int knapsack(const vector<int>& weights, const vector<int>& values, int W, int n) {
    // Create a DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build DP table iteratively
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Either pick item i-1 or don't pick it
                dp[i][w] = max(values[i - 1] + dp[i][w - weights[i - 1]], dp[i - 1][w]); // Note the change here for unbounded knapsack , i-1 to i
            } else {
                // Can't pick item i-1
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    // The answer is in dp[n][W]
    return dp[n][W];
}

int main() {
    vector<int> weights = {1, 2, 3};
    vector<int> values = {10, 15, 40};
    int W = 6; // Maximum weight of knapsack
    int n = weights.size();

    cout << "Maximum value in Knapsack = " << knapsack(weights, values, W, n) << endl;
    return 0;
}
