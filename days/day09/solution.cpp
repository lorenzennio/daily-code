#include "solution.hpp"

long long binomial(int n, int r) {
    if (r > n - r) r = n - r;
    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

long long solution(int const N, int const M) {
    return binomial(N+M-2, N-1);
}