#pragma once
#include <vector>
#include <utility>
#include <cmath>

inline std::vector<std::pair<int, int>> generateKnightMoves() {
    std::vector<std::pair<int, int>> moves;
    for (int dx : {-2, -1, 1, 2}) {
        for (int dy : {-2, -1, 1, 2}) {
            if (std::abs(dx) != std::abs(dy)) {
                moves.push_back({dx, dy});
            }
        }
    }
    return moves;
}
