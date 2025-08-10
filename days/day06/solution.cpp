#include "solution.hpp"

int biased_toss(float bias) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(bias);
    return d(gen) ? 1 : 0;
}

int unbiased_toss(float bias) {
    while (true) {
        int toss1 = biased_toss(bias);
        int toss2 = biased_toss(bias);
        
        if (toss1 != toss2){
            return toss1;
        }
    }
    return -1; // never reached
}

float solution(int tosses, float bias) {
    float heads = 0;

    for (int i = 0; i < tosses; ++i) {
        heads += unbiased_toss(bias);
    }
    
    std::cout << "ratio " << heads / tosses << std::endl;
    return heads / tosses;

}

