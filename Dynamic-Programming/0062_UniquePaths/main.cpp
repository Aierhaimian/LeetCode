#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Memory Search
// Time  Complexity: O(m*n)
// Space Complexity: O(m*n)
class Solution1 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        return dfs(m-1, n-1, dp);
    }
private:
    int d[2][2] = {{0,1}, {1,0}};

    int dfs(int x, int y, vector<vector<int>> &dp) {
        if (x == 0 || y == 0) return 1;
        if (dp[x][y]) return dp[x][y];

        int res = dfs(x-1, y, dp) + dfs(x, y-1, dp);
        return dp[x][y] = res;
    }
};

// Dynamic Programming
// Time  Complexity: O(m*n)
// Space Complexity: O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    }
};

int main()
{

    return 0;
}

