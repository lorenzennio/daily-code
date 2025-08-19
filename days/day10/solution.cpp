#include "solution.hpp"

int solution(std::vector<std::vector<char>> &input) {
    if (input.empty() || input[0].empty()) return 0;

    int rows = input.size();
    int cols = input[0].size();
    int toRemove = 0;

    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows - 1; ++i) {
            if (input[i][j] > input[i + 1][j]) {
                toRemove++;
                break;
            }
        }
    }
    return toRemove;
}
