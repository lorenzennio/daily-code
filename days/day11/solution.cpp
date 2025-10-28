#include "solution.hpp"

int solution(int n) {
    int nr_coins = 0;

    int avail_coins[] = {25, 10, 5, 1};

    for (int c : avail_coins) {
        nr_coins += n / c;
        n = n % c;
    }

    return nr_coins;
}