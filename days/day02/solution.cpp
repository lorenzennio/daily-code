#include "solution.hpp"

std::vector<int> solution(const std::vector<int>& a) {

    // calculate product of all numbers
    int product = 1;
    for (int n : a){
        product *= n;
    }

    // populate new vector with product divided by number
    std::vector<int> result;

    for (int n : a) {
        result.push_back(product / n);
    }

    std::cout << print_vector(a) << " -> " << print_vector(result) << std::endl;

    return result;
}