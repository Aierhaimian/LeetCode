#include <iostream>
#include <cmath>

// Closed Form
// https://en.wikipedia.org/wiki/Fibonacci_number
//
// Time Complexity: O(logn)
// Space Complexity: O(logn)
class Solution {
public:
    int fib(int N) {
        double a = (1. + std::sqrt(5.))/2.0;
        double b = (1. - std::sqrt(5.))/2.0;
        return (int)((std::pow(a, N) - std::pow(b, N))/std::sqrt(5) + 0.5);
    }
};

int main(int args, char** argv)
{
    std::cout << Solution().fib(atoi(argv[1])) << std::endl;
    return 0;
}

