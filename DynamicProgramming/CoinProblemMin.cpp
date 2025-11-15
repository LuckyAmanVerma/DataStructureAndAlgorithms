/*
Problem: Given a set of coin denominations and a target amount, determine the minimum number of coins needed to make up that amount. If it's not possible to make the amount with the given denominations, return -1.
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minCoins(const vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX - 1));

    // Initialize the first column to 0 (0 coins needed to make amount 0)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (coins[i - 1] <= j) {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return (dp[n][amount] == INT_MAX - 1) ? -1 : dp[n][amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 8;
    int result = minCoins(coins, amount);
    if (result != -1) {
        cout << "Minimum coins needed: " << result << endl;
    } else {
        cout << "Not possible to make the amount with the given denominations." << endl;
    }
    return 0;
}