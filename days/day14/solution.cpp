#include "solution.hpp"

int game(int goal0, int goal1) {
    dice d;
    int roll0 = d.roll();
    int roll1 = d.roll();
    int count = 2;
    while (true) {
        if (roll0 == goal0 && roll1 == goal1){
            return count;
        }
        roll0 = roll1;
        roll1 = d.roll();
        count +=1;
    }
    return -1;
}

float expected(int goal0, int goal1, int n_games) {
    long long n_rolls = 0;
    for (int i = 0; i < n_games; i++) {
        n_rolls += game(goal0, goal1);
    }
    return float(n_rolls) / n_games;
}

std::tuple<float, float> solution (int n_games){
    float expected_56 = expected(5, 6, n_games);
    float expected_55 = expected(5, 5, n_games);

    std::tuple<float, float> results(expected_56, expected_55);
    return results;
}