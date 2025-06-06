#include <iostream>
#include <cassert>
#include "../days/day02/solution.hpp"

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> s = {120, 60, 40, 30, 24};
    assert(solution(a) == s);
    assert(solution_no_division(a) == s);

    a = {3, 2, 1};
    s = {2, 3, 6};
    assert(solution(a) == s);
    assert(solution_no_division(a) == s);

    a = {1, 0, 3, 4, 5};
    s = {0, 60, 0, 0, 0};
    assert(solution(a) == s);
    assert(solution_no_division(a) == s);

    a = {1, 2, 0, 4, 0};
    s = {0, 0, 0, 0, 0};
    assert(solution(a) == s);
    assert(solution_no_division(a) == s);

    std::cout << "✅ All tests passed!" << std::endl;
    return 0;
}