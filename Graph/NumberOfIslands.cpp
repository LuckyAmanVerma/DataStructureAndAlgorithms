/*
Based on the LeetCode problem "Island Perimeter"
Given an n x m grid of 'W' (Water) and 'L' (Land), the task is to count the number of islands. 
An island is a group of adjacent 'L' cells connected horizontally, vertically, or diagonally, and it is surrounded
Input: grid[][] = [['L', 'L', 'W', 'W', 'W'],
                            ['W', 'L', 'W', 'W', 'L'],
                          ['L', 'W', 'W', 'L', 'L'],
                         ['W', 'W', 'W', 'W', 'W'],
                        ['L', 'W', 'L', 'L', 'W']]
Output: 4
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 'W' || visited[i][j]) {
        return;
    }
    if(visited[i][j]) return;
    
    visited[i][j] = true;
    //vertically and horizontally
    dfs(grid, i + 1, j, visited);
    dfs(grid, i - 1, j, visited);
    dfs(grid, i, j + 1, visited);
    dfs(grid, i, j - 1, visited);

    //diagonally
    dfs(grid, i + 1, j + 1, visited);
    dfs(grid, i + 1, j - 1, visited);
    dfs(grid, i - 1, j + 1, visited);
    dfs(grid, i - 1, j - 1, visited);
}

int numberOfIslands (vector<vector<char>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int numberOfIslands = 0;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            if(grid[i][j]=='L' &&!visited[i][j]) {
                dfs(grid,i,j,visited);
                numberOfIslands++;
            }
           
            
        }
    }
    return numberOfIslands;
}

int main() {
    vector<vector<char>> grid = {
        {'L', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'W'}
    };

    int ans = numberOfIslands(grid);
    cout << "Number of Islands: " << ans << endl;

    return 0;
}