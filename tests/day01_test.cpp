#include <iostream>
#include <cassert>
#include "../days/day01/solution.hpp"

int main() {
    int k = 17;
    std::vector<int> a = {10, 15, 3, 7};
    assert(solution(k, a) ==  true);

    k = 3;
    assert(solution(k, a) ==  false);

    std::cout << "✅ All tests passed!" << std::endl;
    return 0;
}