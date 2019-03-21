#include <iostream>
#include <vector>

// Binets Method
// Time  Complexity: O(n)
// space Complexity: O(1)
class Solution {
public:
    int fib(int N) {
        if (N == 0) return 0;
        if (N == 1) return 1;

        int prev = 0, cur = 1;
        for (int i=2; i<=N; i++)
        {
            int f = cur + prev;
            prev = cur;
            cur = f;
        }
        
            return cur;
    }
};

int main(int args, char** argv)
{
    std::cout << Solution().fib(atoi(argv[1])) << std::endl;
    return 0;
}

