#include "solution.hpp"

unordered_map<char, int> solution ( 
    char start, 
    unordered_map<char, unordered_map<char, float>> transitions, 
    int num_steps ) {
        
    for ( auto& transition : transitions ) {
        float cumulative = 0;
        for ( auto& prob : transition.second ) {
            prob.second += cumulative;
            cumulative = prob.second;
        }
    }
    
    char state = start;
    
    unordered_map<char, int> state_counts;
    for ( auto transition : transitions ) {
        state_counts[transition.first] = 0;
    }
    state_counts[state] = 1;
    
    for ( int i = 0; i < num_steps; i++ ) {
        // generate random number between 0 and 1
        float random = (float)rand() / (float)RAND_MAX;

        for ( auto probability : transitions[state] ) {
            if (random <= probability.second){ 
                state = probability.first;
                break;
            }
        }

        state_counts[state] += 1;
    }

    return state_counts;



}