#include <iostream>
#include <random>

#pragma once

int biased_toss(float bias);
int unbiased_toss(float bias);
float solution(int tosses = 10000, float bias = 0.6f);