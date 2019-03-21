#include <iostream>
#include <vector>

// Dynamic Programming
// Time  Complexity: O(n)
// space Complexity: O(n)
class Solution {
public:
    int fib(int N) {
        if (N == 0) return 0;
        if (N == 1) return 1;

        std::vector<int> dp(N+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i=2; i<=N; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
            return dp[N];
    }
};

int main(int args, char** argv)
{
    std::cout << Solution().fib(atoi(argv[1])) << std::endl;
    return 0;
}

