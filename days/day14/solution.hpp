#pragma once

#include <tuple>
#include <random>

#include <iostream>

class dice {
    private:
        // random nr engine
        std::mt19937 rng{std::random_device{}()};
        
        // define distribution
        std::uniform_int_distribution<int> dist;

    public:
        dice(): dist(1,6) {}
        int roll() { return dist(rng); }

};

int game(int goal0, int goal1);

float expected(int goal0, int goal1, int n_games);

std::tuple<float, float> solution (int n_games);