/*
Rat in a maze — lexicographic order: D, L, R, U
Uses a visited matrix and backtracking.
We set visited[x][y] to 1 so that we don't visit the same cell again.
We set visited[x][y] to 0 when backtracking, so we can explore other paths.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int x, int y,
            const vector<vector<int>>& maze,
            const vector<vector<bool>>& visited,
            int n) {
    return (x >= 0 && x < n &&
            y >= 0 && y < n &&
            maze[x][y] == 1 &&
            !visited[x][y]);
}

void solve(int x, int y,
           const vector<vector<int>>& maze,
           vector<vector<bool>>& visited,
           int n,
           string path,                   
           vector<string>& ans) {
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = true;

    // D, L, R, U (lexicographic)
    if (isSafe(x + 1, y, maze, visited, n))
        solve(x + 1, y, maze, visited, n, path + 'D', ans);

    if (isSafe(x, y - 1, maze, visited, n))
        solve(x, y - 1, maze, visited, n, path + 'L', ans);

    if (isSafe(x, y + 1, maze, visited, n))
        solve(x, y + 1, maze, visited, n, path + 'R', ans);

    if (isSafe(x - 1, y, maze, visited, n))
        solve(x - 1, y, maze, visited, n, path + 'U', ans);

    visited[x][y] = false; // backtrack
}

vector<string> ratMaze(vector<vector<int>>& maze) {
    int n = (int)maze.size();
    vector<string> ans;
    if (n == 0 || maze[0][0] == 0 || maze[n-1][n-1] == 0) return ans;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    solve(0, 0, maze, visited, n, "", ans);
    return ans;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 1}
    };

    vector<string> paths = ratMaze(maze);

    for (const string& path : paths) {
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i + 1 < path.size()) cout << ',';
        }
        cout << '\n';
    }

    return 0;
}
