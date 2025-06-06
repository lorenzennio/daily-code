#include <iostream>
#include <cassert>
#include "../days/day02/solution.hpp"

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> s = {120, 60, 40, 30, 24};
    assert(solution(a) == s);

    a = {3, 2, 1};
    s = {2, 3, 6};
    assert(solution(a) == s);

    std::cout << "✅ All tests passed!" << std::endl;
    return 0;
}