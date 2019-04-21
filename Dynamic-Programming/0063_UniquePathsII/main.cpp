#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Dynamic Programming
// Time  Complexity: O(m*n)
// Space Complexity: O(m*n)
class Solution1 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0 || obstacleGrid[0][0]) return 0; // 障碍就在起点

        vector<vector<int64_t>> dp(m, vector<int64_t>(n, -1));
        dp[0][0] = 1;
        for (int j=1; j<n; j++) {
            if (obstacleGrid[0][j])
                dp[0][j] = 0;
            else
                dp[0][j] = dp[0][j-1];
        }

        for (int i=1; i<m; i++) {
            if (obstacleGrid[i][0])
                dp[i][0] = 0;
            else
                dp[i][0] = dp[i-1][0];
        }

        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (obstacleGrid[i][j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// Dynamic Programming
// Time  Complexity: O(m*n)
// Space Complexity: O(n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0 || obstacleGrid[0][0]) return 0; // 障碍就在起点

        vector<int64_t> dp(n, -1);
        dp[0] = 1;

        for (int j=1; j<n; j++)
            if (obstacleGrid[0][j])
                dp[j] = 0;
            else
                dp[j] = dp[j-1];

        for (int i=1; i<m; i++)
            for (int j=0; j<n; j++)
                if (obstacleGrid[i][j])
                    dp[j] = 0;
                else {
                    if (j == 0)
                        dp[j] = dp[j];
                    else
                        dp[j] = dp[j-1] + dp[j];
                }
        return dp[n-1];
    }
};

int main()
{

    return 0;
}

