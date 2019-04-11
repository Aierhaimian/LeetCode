#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Recursive
// Time  Complexity: O(2^n)
// Space Complexity: O(1)
class Solution1 {
public:
    int climbStairs(int n) {
        return calcWays(n);
    }
private:
    int calcWays(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        return calcWays(n-1) + calcWays(n-2);
    }
};

// Memory Search
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    int climbStairs(int n) {
        memo = vector<int>(n+1, -1);
        return calcWays(n);
    }
private:
	vector<int> memo;
    int calcWays(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        if (memo[n] == -1)
            memo[n] = calcWays(n-1) + calcWays(n-2);
         return memo[n];
    }
};

// Dynamic  Programming
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution3 {
public:
    int climbStairs(int n) {
        vector<int> memo(n+2, -1);
        memo[1] = 1;
        memo[2] = 2;

        for (int i = 3; i<=n; i++)
            memo[i] = memo[i-1] + memo[i-2];
        return memo[n];
    }
};

int main()
{
    return 0;
}

