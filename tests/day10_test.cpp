#include <iostream>
#include <cassert>
#include "../days/day10/solution.hpp"

int main() {

    std::vector<std::vector<char>> input = {
        {'c', 'b', 'a'},
        {'d', 'a', 'f'},
        {'g', 'h', 'i'}
    };
    assert(solution(input) == 1);

    std::vector<std::vector<char>> sortedInput = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'}
    };
    assert(solution(sortedInput) == 0);

    std::vector<std::vector<char>> multipleRemoveInput = {
        {'z', 'y', 'x'},
        {'w', 'v', 'u'},
        {'t', 's', 'r'}
    };
    assert(solution(multipleRemoveInput) == 3);

    std::vector<std::vector<char>> emptyInput = {};
    assert(solution(emptyInput) == 0);

    std::vector<std::vector<char>> singleRowInput = {
        {'a', 'b', 'c'}
    };
    assert(solution(singleRowInput) == 0);

    std::cout << "✅ All tests passed!" << std::endl;
    return 0;
}
