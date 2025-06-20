#include "solution.hpp"

char solution(std::string& stream) {

    char current = '0';
    int count = 0;

    std::srand(std::time(nullptr));

    for (auto &ch : stream) {

        int rand = std::rand() % (count+1);

        if (rand == 0) {

            current = ch;

        }

        ++count;
    }

    return current;

}
