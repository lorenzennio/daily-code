#include "solution.hpp"

std::vector<int> solution(const std::vector<int>& a) {

    // Three cases: (1) more than one 0, (2) one 0, (3) no 0

    // calculate product of all numbers and count zeros
    int product = 1;
    int zero_count = 0;
    int zero_index = -1;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == 0) {
            zero_count++;
            zero_index = i;  // save the zero index
        } else {
            product *= a[i];
        }
    }

    // initialize all 0 (case (1))
    std::vector<int> result(a.size(), 0);

    if (zero_count==1) {
        // case (2)
        result[zero_index] = product;
    } else if (zero_count==0) {
        // case(3)
        for (size_t i = 0; i < a.size(); ++i) {
            result[i] = product / a[i];
        }
    }

    std::cout << print_vector(a) << " -> " << print_vector(result) << std::endl;

    return result;
}

std::vector<int> solution_no_division(const std::vector<int>& a) {
    size_t n = a.size();
    std::vector<int> result(n);
    std::vector<int> left_products(n, 1);
    std::vector<int> right_products(n, 1);

    for (size_t i = 1; i < n ; ++i) {
        left_products[i] = left_products[i-1]*a[i-1];
    }

    for (size_t i = n-2; i < n ; --i) {
        right_products[i] = right_products[i+1]*a[i+1];
    }

    for (size_t i = 0; i < n; ++i) {
        result[i] = left_products[i] * right_products[i];
    }

    std::cout << print_vector(a) << " -> " << print_vector(result) << std::endl;

    return result;

}