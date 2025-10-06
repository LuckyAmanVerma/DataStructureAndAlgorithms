/*
Knapsack Problem using Dynamic Programming
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
You cannot break an item, either pick the complete item or don’t pick it (0-1 property).
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//memoization approach
int knapsack(const vector<int>& weights, const vector<int>& values,int W,  int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    if (n == 0 || W == 0) {
        return 0;
    }
    if(dp[n][W] != 0) {
        return dp[n][W];
    }

    if(weights[n - 1] <= W) {
        dp[n][W] = max(values[n - 1] + knapsack(weights, values, W - weights[n - 1], n - 1),
                       knapsack(weights, values, W, n - 1));
    } else {
        dp[n][W] = knapsack(weights, values, W, n - 1);
    }
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