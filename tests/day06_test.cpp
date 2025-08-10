#include <iostream>
#include <cassert>
#include "../days/day06/solution.hpp"

void assertFloatNear(float a, float b, float tol = 1e-6f) {
    assert(std::fabs(a - b) <= tol && "Floats differ by more than tolerance");
}

int main() {
    {
        assertFloatNear(solution(10000, 0.6f), 0.5f, 0.01f);
    }
    {
        assertFloatNear(solution(10000, 0.9f), 0.5f, 0.01f);
    }
    std::cout << "✅ All tests passed!" << std::endl;
    return 0;
}
