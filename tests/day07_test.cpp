#include <iostream>
#include <cassert>
#include "../days/day07/solution.hpp"

int main() {
    {
    std::vector<std::vector<int>> bishops = {{0, 0}, {1, 2}, {2, 2}, {4, 0}};
    assert(solution(bishops) == 2);
    assert(better_solution(bishops) == 2);
    }

    // No bishops
    {
        std::vector<std::vector<int>> bishops = {};
        assert(solution(bishops) == 0);
        assert(better_solution(bishops) == 0);
    }

    // Single bishop
    {
        std::vector<std::vector<int>> bishops = {{3, 3}};
        assert(solution(bishops) == 0);
        assert(better_solution(bishops) == 0);
    }

    // Two bishops not attacking each other
    {
        std::vector<std::vector<int>> bishops = {{0, 0}, {1, 3}};
        assert(solution(bishops) == 0);
        assert(better_solution(bishops) == 0);
    }

    // Two bishops attacking
    {
        std::vector<std::vector<int>> bishops = {{0, 0}, {2, 2}};
        assert(solution(bishops) == 1);
        assert(better_solution(bishops) == 1);
    }

    // Three bishops on the same diagonal (↘)
    {
        std::vector<std::vector<int>> bishops = {{0, 0}, {1, 1}, {2, 2}};
        // 3 bishops on same diagonal → C(3, 2) = 3 pairs
        assert(solution(bishops) == 3);
        assert(better_solution(bishops) == 3);
    }

    // Bishops on both ↘ and ↙ diagonals
    {
        std::vector<std::vector<int>> bishops = {{0, 3}, {1, 2}, {2, 1}, {3, 0}};
        // All on ↙ diagonal → 4 bishops → C(4, 2) = 6 pairs
        assert(solution(bishops) == 6);
        assert(better_solution(bishops) == 6);
    }

    // Mixed case: some attacking, some not
    {
        std::vector<std::vector<int>> bishops = {{0, 0}, {1, 2}, {3, 0}, {2, 4}, {4, 4}};
        // (0,0)-(1,2) attack ↙
        // (3,0)-(1,2) attack ↘
        // (4,4)-(2,4) attack ↙
        // Check all: total 3 pairs
        assert(solution(bishops) == 2);
        assert(better_solution(bishops) == 2);
    }

    std::cout << "✅ All tests passed!" << std::endl;
    return 0;
}
