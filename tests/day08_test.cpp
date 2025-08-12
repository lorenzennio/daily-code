#include <iostream>
#include <cassert>
#include "../days/day08/solution.hpp"

int main() {
    {
        std::vector<int> input1 =  {-10, -10, 5, 2};
        assert(solution(input1) == 500);
        assert(better_solution(input1) == 500);
    }
    {
        std::vector<int> input2 =  {1, 2, 3};
        assert(solution(input2) == 6);
        assert(better_solution(input2) == 6);
    }
    {
        std::vector<int> input3 =  {-1, -2, -3};
        assert(solution(input3) == -6);
        assert(better_solution(input3) == -6);
    }
    std::cout << "✅ All tests passed!" << std::endl;
    return 0;
}
