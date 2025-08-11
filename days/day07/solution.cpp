#include "solution.hpp"

int solution(std::vector<std::vector<int>> const& bishops) {
    int count = 0;
    for (size_t i = 0; i < bishops.size(); ++i) {
        for (size_t j = i + 1; j < bishops.size(); ++j) {
            if (std::abs(bishops[i][0] - bishops[j][0]) == std::abs(bishops[i][1] - bishops[j][1])) {
                ++count;
            }
        }
    }
    return count;
}