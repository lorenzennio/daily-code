#pragma once

#include <unordered_map>
#include <stdexcept>
using namespace std;

unordered_map<char, int> solution ( char start, unordered_map<char, unordered_map<char, float>> transitions, int num_steps );
