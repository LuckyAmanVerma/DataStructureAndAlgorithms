#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#include "KnightMoves.h"

struct Position {
    int x, y, dist;
};

bool isValid(int x, int y, int N, vector<vector<bool>> &visited) {
    return (x >= 0 && x < N && y >= 0 && y < N && !visited[x][y]);
}

int minStepsByKnight(int N, int start_x, int start_y, int target_x, int target_y) {
    if (start_x == target_x && start_y == target_y) return 0;

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<Position> q;

    q.push({start_x, start_y, 0});
    visited[start_x][start_y] = true;

    vector<pair<int, int>> moves = generateKnightMoves();

    while (!q.empty()) {
        Position curr = q.front();
        q.pop();

        for (const auto& move : moves) {
            int newX = curr.x + move.first;
            int newY = curr.y + move.second;

            if (newX == target_x && newY == target_y)
                return curr.dist + 1;

            if (isValid(newX, newY, N, visited)) {
                visited[newX][newY] = true;
                q.push({newX, newY, curr.dist + 1});
            }
        }
    }

    return -1; // If target not reachable (theoretically shouldn't happen on a chessboard)
}

int main() {
    int N = 8; // Standard chessboard size
    int start_x = 0, start_y = 0; // Starting position (0-based indexing)
    int target_x = 7, target_y = 7; // Target position

    int steps = minStepsByKnight(N, start_x, start_y, target_x, target_y);

    cout << "Minimum steps by knight: " << steps << endl;

    return 0;
}
