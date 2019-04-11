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
    int integerBreak(int n) {
        assert(n >= 2);
        return breakInteger(n);
    }
private:
    int max3(int a, int b, int c)
    {
        return max(a, max(b, c));
    }

    // 将n进行分割（至少分割两部分），可以获得的最大乘积
    int breakInteger(int n)
    {
        if (n == 1) return 1;

        int res = -1;
        for (int i=1; i<=n-1; i++)
            res = max3(res, i*(n-i), i*breakInteger(n-i));

        return res;
    }
};

// Memory Search
// Time  Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    int integerBreak(int n) {
        assert(n>=2);

        memo = vector<int>(n+1, -1);

        return breakInteger(n);

    }
private:
    vector<int> memo;
    int max3(int a, int b, int c)
    {
        return max(a, max(b, c));
    }

    // 将n进行分割（至少分割两部分），可以获得的最大乘积
    int breakInteger(int n)
    {
        if (n == 1) return 1;

        if (memo[n] != -1) return memo[n];

        int res = -1;
        for (int i=1; i<=n-1; i++)
            res = max3(res, i*(n-i), i*breakInteger(n-i));

        memo[n] = res;

        return res;
    }
};

// Dynaic Programming
// Time  Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    int integerBreak(int n) {
        assert(n >= 2);
        //memo[i]将数字分割（至少分割两部分）可以获得的最大乘积
        std::vector<int> memo(n+1, -1);

        memo[1] = 1;

        for (int i=2; i<=n; i++)
            //求解memo[i]
            for (int j=1; j<=i-1; j++)
                // j + (i - j)
                memo[i] = max3(memo[i], j*(i-j), j*memo[i-j]);
        return memo[n];
    }
private:
    int max3(int a, int b, int c)
    {
        return max(a, max(b, c));
    }
};

int main()
{
    int n;
    while (cin >> n)
        cout << n << "--" << Solution().integerBreak(n) << endl;
    return 0;
}

