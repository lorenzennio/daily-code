#include "solution.hpp"

bool solution(int k, const std::vector<int>& a){
    
    for (size_t i = 0; i + 1 < a.size(); ++i) {
        auto it = std::find(a.begin()+i+1, a.end(), k-a[i]);
        if (it != a.end()) {
            message(k, a, true);
            return true;
        }
    }

    message(k, a, false);

    return false;
}

void message(int k, const std::vector<int>& a, bool b) {
    if (b) {
        std::cout << k << " can be made from two values in [";
    } else {
        std::cout << k << " can NOT be made from two values in [";
    }
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i];
        if (i + 1 < a.size()) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}