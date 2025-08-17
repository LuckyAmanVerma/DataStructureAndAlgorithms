/*
Print elements of a matrix in spiral order
Input: 
[ [ 1, 2, 3 ],
  [ 4, 5, 6 ],
  [ 7, 8, 9 ] ]

Output: 1 2 3 6 9 8 7 4 5
*/

#include<iostream>
#include<vector>
using namespace std;

void spiralOrder(vector<vector<int>> &matrix ,vector<int> &ans) {

    int rows = matrix.size();
    int cols = matrix[0].size();
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    int dir=0;
    while (top <= bottom && left <= right) {
        // Traverse from left to right
        if(dir==0) {
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;
        }
        dir++;
        

        // Traverse from top to bottom
        if(dir==1){
            for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;
    }
    dir++;

        // Traverse from right to left
       
           if(dir==2){
             for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        dir++;

        // Traverse from bottom to top
       
          if(dir==3) {
             for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        dir++;
        if(dir==4) {
            dir=0;
        }
        
    }
}
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> ans;
    ans.reserve(matrix.size() * matrix[0].size()); // Reserve space for the result
    spiralOrder(matrix, ans);

    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
 