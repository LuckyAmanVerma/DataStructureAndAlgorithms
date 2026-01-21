/*Print the lowest common subsequence
 string X = "AGGTAB";
    string Y = "GXTXAYB";
    LCS is "GTAB"
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string printLCS(const string &X, const string &Y) {
    int m = X.length(), n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Backtrack to find LCS string
    string ans;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            ans.push_back(X[i - 1]);
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    string lcs = printLCS(X, Y);
    cout << "The Longest Common Subsequence is: " << lcs << endl;
    return 0;
}