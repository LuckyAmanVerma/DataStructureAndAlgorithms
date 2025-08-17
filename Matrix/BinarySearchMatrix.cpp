/*
Input matrix = mXn - m=5, n=5  target = 20
[[0,5,6,8,9],
 [1,10,11,12,13],
 [2,14,15,16,17],
 [3,18,19,20,21],
 [4,22,23,24,25]
]
 Time Complexity: O(log(m*n))
 Space Complexity: O(1)
*/

#include<iostream>
#include<vector>
using namespace std;

pair<int,int> binarySearch(vector<vector<int>> &matrix,int &target) {
    int m=matrix.size();
    int n=matrix[0].size();
    int start=0;
    int end = (n*m)-1;
    while(start<=end) {
        int mid =start+(end-start)/2;
        int row = mid/n; int col = mid%n;
        if(matrix[row][col]==target) {
            return {row,col};
        }
        else if(matrix[row][col]<target) {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return {-1,-1};
}

int main() {
    vector<vector<int>> matrix = {
        { 5, 6, 8, 9},
        { 10, 11, 12, 13},
        {14, 15, 16, 17},
        {18, 19, 20, 21},
        {22, 23, 24, 25}
    };
    int target = 5;
    pair<int,int> ans = binarySearch(matrix,target);
    if (ans.first!=-1) {
        cout << "Element found in the matrix at position " << ans.first<<" "<<ans.second<<endl;
    } else {
        cout << "Element not found in the matrix." << ans.first<<" "<<ans.second<< endl;
    }

}