/*
Lowest common subsequence (LCS) problem using Dynamic Programming
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//recursive way

int LCSRecursive(const string &X, const string &Y, int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + LCSRecursive(X, Y, m - 1, n - 1);
    else
        return max(LCSRecursive(X, Y, m, n - 1), LCSRecursive(X, Y, m - 1, n));
}

//memoization way

int LCSMemoization(const string &X, const string &Y, int m, int n, vector<vector<int>> &dp) {
    if (m == 0 || n == 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];
    if (X[m - 1] == Y[n - 1])
        dp[m][n] = 1 + LCSMemoization(X, Y, m - 1, n - 1, dp);
    else
        dp[m][n] = max(LCSMemoization(X, Y, m, n - 1, dp), LCSMemoization(X, Y, m - 1, n, dp));
    return dp[m][n];
}

//top-down approach

int LCSBottomUp(const string &X, const string &Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    vector<vector<int>> dp(X.length() + 1, vector<int>(Y.length() + 1, -1));
    int m = X.length();
    int n = Y.length();
    cout << "Length of LCS is " << LCSRecursive(X, Y, m, n) << endl;
    cout << "Length of LCS using Memoization is " << LCSMemoization(X, Y, m, n, dp) << endl;
    return 0;
}