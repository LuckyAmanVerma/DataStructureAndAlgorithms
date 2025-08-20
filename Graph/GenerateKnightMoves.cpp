#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> generateKnightMoves() {
    vector<pair<int, int>> moves;

    for (int dx : {-2, -1, 1, 2}) {
        for (int dy : {-2, -1, 1, 2}) {
            // Only allow moves where absolute dx and dy are 1 and 2 in some order
            if (abs(dx) != abs(dy)) {
                moves.push_back({dx, dy});
            }
        }
    }
    return moves;
}

int main() {
    auto knightMoves = generateKnightMoves();

    cout << "Knight moves (dx, dy):\n";
    for (auto &move : knightMoves) {
        cout << "(" << move.first << ", " << move.second << ")\n";
    }

    return 0;
}
