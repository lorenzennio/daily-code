#include <iostream>
#include <cassert>
#include "../days/day12/solution.hpp"

int main() {
    
    std::vector<int> input   = {3, 4, 9, 6, 1};
    std::vector<int> sol     = {1, 1, 2, 1, 0};

    assert(solution(input) == sol);

    std::cout << "✅ All tests passed!" << std::endl;
    return 0;
}
