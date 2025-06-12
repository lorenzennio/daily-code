#include "solution.hpp"

int solution_old(const std::string& message) {

    if(message.empty()) return 1;

    int count = 0;
    for (int i = 1; i <= 26; ++i) {
        std::string i_str = std::to_string(i);
        if (message.rfind(i_str, 0) == 0){
            count += solution_old(message.substr(i_str.length()));
        }
    }

    return count;
}

int solution(const std::string& message) {
    if (message.empty() || message[0] == '0') return 0;

    size_t n = message.length();
    std::vector<int> dp(n + 1, 0);  // dp[i] = # of ways to decode message[0..i-1]
    dp[0] = 1;                      // empty string has 1 way to decode
    dp[1] = 1;                      // one valid character

    for (size_t i = 2; i <= n; ++i) {
        char one = message[i - 1];
        std::string two = message.substr(i - 2, 2);

        // Single digit (non-zero)
        if (one != '0') {
            dp[i] += dp[i - 1];
        }

        // Two digits (between 10 and 26 inclusive)
        if (two >= "10" && two <= "26") {
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}