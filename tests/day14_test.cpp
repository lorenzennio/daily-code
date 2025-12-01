#include <iostream>
#include <cassert>
#include "../days/day14/solution.hpp"

int main() {

    auto [exp56, exp55] = solution(10000);

    assert(exp56 > 34.0 && exp56 < 38.0); // expected around 36.0
    assert(exp55 > 40.0 && exp55 < 44.0); // expected around 42.0

    std::cout << "✅ All tests passed!" << std::endl;
    return 0;
}
