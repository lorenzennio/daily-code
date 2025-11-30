#include <iostream>
#include <cassert>
#include "../days/day13/solution.hpp"

int main() {
    unordered_map<char, unordered_map<char, float>> transitions = {
        {'a', {{'a', 0.9}, {'b', 0.075}, {'c', 0.025}}},
        {'b', {{'a', 0.15}, {'b', 0.8}, {'c', 0.05}}},
        {'c', {{'a', 0.25}, {'b', 0.25}, {'c', 0.5}}}
    };

    unordered_map<char, int> state_counts = solution('a', transitions, 5000);

    assert(state_counts['a'] + state_counts['b'] + state_counts['c'] == 5001); // including the initial state

    std::cout << "State counts after 5000 steps starting from 'a':" << std::endl;
    std::cout << "a: " << state_counts['a'] << std::endl;
    std::cout << "b: " << state_counts['b'] << std::endl;
    std::cout << "c: " << state_counts['c'] << std::endl;

    std::cout << "✅ All tests passed!" << std::endl;
    return 0;
}
