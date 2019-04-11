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
    int numSquares(int n) {
        return squaresNum(n);
    }
private:
    int mini = INT_MAX;
    int squaresNum(int n)
    {
        if (n == 0)
            return 0;

        int res = INT_MAX;
        for (int i=1; n-i*i>=0; i++)
            res = min(res, 1+squaresNum(n-i*i));
        return res;
    }
};

// Memory Search
// Time  Complexity: O(n^2)
// Space Complexity: O(n)
class Solution2 {
public:
    int numSquares(int n) {
    	memo = vector<int>(n+1, -1);
        return squaresNum(n);
    }
private:
	std::vector<int> memo;
    int mini = INT_MAX;
    int squaresNum(int n)
    {
        if (n == 0)
            return 0;

        if (memo[n] != -1)
        	return memo[n];

        int res = INT_MAX;
        for (int i=1; n-i*i>=0; i++)
            res = min(res, 1+squaresNum(n-i*i));
        memo[n] = res;
        return res;
    }
};

// Dynamic Programming
// Time  Complexity: O(n^2)
// Space Complexity: O(n)
class Solution3 {
public:
    int numSquares(int n) {
        vector<int> memo(n+1, INT_MAX);

        memo[0] = 0;

        for (int i=1; i<=n; i++)
        	for (int j=1; i-j*j>=0; j++)
        		memo[i] = min(memo[i], 1+memo[i-j*j]);
        return memo[n];
    }
};

// BFS
// Time  Complexity: O()
// Space Complexity: O()
class Solution {
public:
    int numSquares(int n) {

    }
};

int main()
{
    int n;
    while (cin>>n)
        cout << n << "--" << Solution().numSquares(n) << endl;
    return 0;
}

