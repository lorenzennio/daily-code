#include "solution.hpp"

std::vector<int> solution(std::vector<int>& input) {

    std::vector<int> sol;

    for (size_t i = 0; i < input.size()-1; ++i){
        int count = 0;
        // count smaller number to the right
        for (size_t j = i+1; j < input.size(); ++j){
            if (input[j] < input[i]) {count++;}
        }
        sol.push_back(count);
    }
    
    // no number right of last entry
    sol.push_back(0);

    return sol;
}