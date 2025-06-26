#include "solution.hpp"

std::optional<std::vector<std::string>> solution(
    const std::unordered_set<std::string>& dict, 
    const std::string& sentence) {

    if (dict.find(sentence)!= dict.end()) return std::vector<std::string>{sentence};

    for (size_t i = 1; i < sentence.length(); ++i){
        std::string prefix = sentence.substr(0, i);
        if (dict.find(prefix) != dict.end()) {
            auto result = solution(dict, sentence.substr(i));
            if (result.has_value()){
                result->insert(result->begin(), prefix);
                return result;
            }
        }
    }

    return std::nullopt; 
}