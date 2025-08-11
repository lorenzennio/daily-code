#include <iostream>
#include <cassert>
#include "../days/day07/solution.hpp"

int main() {
    
    std::vector<std::vector<int>> bishops = {{0, 0}, {1, 2}, {2, 2}, {4, 0}};
    assert(solution(bishops) == 2);

    // std::vector<std::vector<int>> bishops2 = {{0, 0}, {1, 1}, {2, 2}, {3, 3}};
    // assert(solution(bishops2) == 6);

    // std::vector<std::vector<int>> bishops3 = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
    // assert(solution(bishops3) == 2);

    std::cout << "✅ All tests passed!" << std::endl;
    return 0;
}
