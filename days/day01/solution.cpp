#include "solution.hpp"

bool solution(int k, const std::vector<int>& a){
    
    std::unordered_set<int> seen;

    for (int num : a) {
        if (seen.contains(k - num)) {
            message(k, a, true);
            return true;
        }
        seen.insert(num);
    }

    message(k, a, false);
    return false;

    return false;
}

void message(int k, const std::vector<int>& a, bool found) {
    std::cout << k << " can" << (found ? "" : " NOT") << " be made from two values in [";
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i];
        if (i + 1 < a.size()) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}