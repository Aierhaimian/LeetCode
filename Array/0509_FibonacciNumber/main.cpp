#include <iostream>

// Recursive
// Time  Complexity: O(2^n)
// space Complexity: O(1)
class Solution {
public:
    int fib(int N) {
        if (N == 0)
            return 0;
        if (N == 1)
            return 1;
        else
            return fib(N-1) + fib(N-2);
    }
};

int main(int args, char** argv)
{
    std::cout << Solution().fib(atoi(argv[1])) << std::endl;
    return 0;
}

