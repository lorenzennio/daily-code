#include <iostream>
#include <cassert>
#include "../days/day03/solution.hpp"

int main() {

    assert(solution_old("111") == 3);
    assert(solution_old("12") == 2);
    assert(solution_old("101") == 1);
    assert(solution_old("1111111111") == 89);

    assert(solution("111") == 3);
    assert(solution("12") == 2);
    assert(solution("101") == 1);
    assert(solution("1111111111") == 89);

    std::cout << "✅ All tests passed!" << std::endl;
    return 0;
}
