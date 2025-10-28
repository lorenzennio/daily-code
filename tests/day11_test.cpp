#include <iostream>
#include <cassert>
#include "../days/day11/solution.hpp"

int main() {
    
    assert(solution( 1) == 1);
    assert(solution( 5) == 1);
    assert(solution(10) == 1);
    assert(solution(25) == 1);
    assert(solution(16) == 3);
    assert(solution(18) == 5);

    std::cout << "✅ All tests passed!" << std::endl;
    return 0;
}
