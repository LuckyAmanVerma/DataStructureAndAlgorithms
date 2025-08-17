/*
Input: arr[][] = [[0,1,1,1]
                , [0,0,1,1], 
                  [1,1,1,1], 
                  [0,0,0,0]]
Output: 2
Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.

METHOD IS CALLED staircase”  OR TOP_RIGHT APPROACH
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int bruteForce(vector<vector<int>> &arr) {
        int row = arr.size();
        int col = arr[0].size();
        
        int maxCount = 0;   // to store max number of 1s
        int ans = -1;       // to store row index
        
        for (int i = 0; i < row; i++) {
            int count = 0;
            for (int j = 0; j < col; j++) {
                if (arr[i][j] == 1) {
                    count++;
                }
            }
            if (count > maxCount) {   // update when a better row is found
                maxCount = count;
                ans = i;
            }
        }
        return ans;
    }

int rowWithMaxOnesOptimized(const vector<vector<int>> &matrix) {
    int r = matrix.size();
    int c = matrix[0].size();

    int maxRowIndex = -1;
    int j = c - 1;  // Start from the top-right corner

    for (int i = 0; i < r; i++) {
        // Move left while the current element is 1
        while (j >= 0 && matrix[i][j] == 1) {  // j k value , next row m tbhi aage bdegi , jb us row m jyada one's honge
            j--;
            maxRowIndex = i;  // Update max row index when we find more 1s
        }
        // If we reach beginning of row, no need to continue further
        if (j < 0) break;
    }

    return maxRowIndex;
}


int main() {
    vector<vector<int>> matrix = {
        {0, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
    // cout << "Row with maximum 1s (Brute Force): " << bruteForce(matrix) << endl;
    cout << "Row with maximum 1s (Optimized): " << rowWithMaxOnesOptimized(matrix) << endl;
    return 0;
}
