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

int better_solution(std::vector<std::vector<int>> const& bishops) {
    std::unordered_map<int, int> diag1, diag2;

    for (const auto& bishop : bishops) {
        int d1 = bishop[0] - bishop[1]; // main diagonal
        int d2 = bishop[0] + bishop[1]; // anti diagonal

        diag1[d1]++;
        diag2[d2]++;
    }

    auto countPairs = [](auto& diag) {
        long long pairs = 0;
        for (auto& [_, cnt] : diag) {
            if (cnt > 1) {
                pairs += 1LL * cnt * (cnt - 1) / 2;
            }
        }
        return pairs;
    };

    return static_cast<int>(countPairs(diag1) + countPairs(diag2));
}

