#include <iostream>
#include <cassert>
#include "../days/day05/solution.hpp"

int main() {

    {
        std::unordered_set<std::string> dict = {"quick", "brown", "the", "fox"};
        std::string sentence = "thequickbrownfox";
        std::vector<std::string> sol = {"the", "quick", "brown", "fox"};
        assert(solution(dict, sentence) == sol);
    }

    {
        std::unordered_set<std::string> dict = {"bed", "bath", "bedbath", "and", "beyond"};
        std::string sentence = "bedbathandbeyond";
        std::vector<std::string> sol1 = {"bed", "bath", "and", "beyond"};
        std::vector<std::string> sol2 = {"bedbath", "and", "beyond"};
        auto result = solution(dict, sentence);
        assert(result == sol1 || result == sol2);
    }

    {
        std::unordered_set<std::string> dict = {"bed", "bath", "bedbaths", "and", "beyond"};
        std::string sentence = "bedbathsandbeyond";
        std::vector<std::string> sol = {"bedbaths", "and", "beyond"};
        assert(solution(dict, sentence) == sol);
    }

    {
        std::unordered_set<std::string> dict = {"bed", "bath", "bedbaths", "a", "beyond"};
        std::string sentence = "bedbathsandbeyond";
        auto sol = std::nullopt;
        assert(solution(dict, sentence) == sol);
    }

    std::cout << "✅ All tests passed!" << std::endl;
    return 0;
}
