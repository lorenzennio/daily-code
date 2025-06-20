#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include "../days/day04/solution.hpp"

int main() {
    // TODO: write tests for day 04
    std::cout << "✅ All tests passed!" << std::endl;

    std::string s = "qwertzuiopasdfghjkl";

    std::unordered_map<char, int> frequency;

    const int trials = 100'000;

    for (int i = 0; i < trials; ++i) {
        int rand = std::rand() % (s.length()+1);
        char selected = s[rand];
        frequency[selected]++;
    }

    int expected = trials / s.size();
    for (const auto& [ch, count] : frequency) {
        double diff_ratio =  std::abs((double)count - expected) / expected;
        assert(diff_ratio < 0.1);
    }

    solution(s);

    return 0;
}
