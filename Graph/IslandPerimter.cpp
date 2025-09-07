/*
https://www.youtube.com/watch?v=O34v6f6s3lQ
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). 
The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
Using DFS

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Once we visit any element set it to -1 , 
While traversing check if it is -1 , then it is already visited no need to visit 


*/

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &grid,int i,int j,int &peri,vector<vector<bool>> &visited) {
    if(i<0 || i>=grid.size() || j<0||j>=grid[0].size() ||grid[i][j]==0) {
        peri++;
        return;
    }
    if(visited[i][j]) {
        return;
    }
    visited[i][j]=true; //mark visited
    dfs(grid,i+1,j,peri,visited);
    dfs(grid,i-1,j,peri,visited);
    dfs(grid,i,j+1,peri,visited);
    dfs(grid,i,j-1,peri,visited);

}

int islandPerimeter(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int peri =0;
    vector<vector<bool>> visited(rows,vector<bool>(cols,false));
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            if(grid[i][j]==1) {
                dfs(grid,i,j,peri,visited);
                return peri;
            }
        }
    }
    return -1;

}

int main() {
    vector<vector<int>> grid = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };

    int perimeter = islandPerimeter(grid);
    cout << "Island Perimeter: " << perimeter << endl;

    return 0;
}