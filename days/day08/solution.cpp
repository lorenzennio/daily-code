#include "solution.hpp"

int solution(std::vector<int> const& input) {

    std::vector<int> sorted_input = input;
    std::sort(sorted_input.begin(), sorted_input.end());

    int product1 = sorted_input[0] * sorted_input[1] * sorted_input.back(); // Two smallest, one largest
    int product2 = sorted_input[sorted_input.size() - 1] * sorted_input[sorted_input.size() - 2] * sorted_input[sorted_input.size() - 3]; // Three largest

    return std::max(product1, product2);
}

int better_solution(std::vector<int> const& input) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int num : input) {
        if (num > max1) {
            max3 = max2;
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max3 = max2;
            max2 = num;
        } else if (num > max3) {
            max3 = num;
        }

        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }

    long long product1 = min1 * min2 * max1; // Two smallest, one largest
    long long product2 = max1 * max2 * max3; // Three largest

    return static_cast<int>(std::max(product1, product2));
}