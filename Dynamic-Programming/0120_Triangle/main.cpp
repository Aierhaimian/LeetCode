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
    int minimumTotal(vector<vector<int>>& triangle) {
        m = triangle.size();
        if (m == 0) return 0;
        return miniSum(triangle, 0, 0, 0);
    }
private:
    int m;
    int miniSum(vector<vector<int>> &tri, int x, int y, int mini)
    {
        mini += tri[x][y];

        if (x+1 == m)
        {
            return mini;
        }

        int mini1 = miniSum(tri, x+1, y, mini);
        int mini2 = miniSum(tri, x+1, y+1, mini);

        return mini1 < mini2 ? mini1 : mini2;
    }
};

// Memory search
// Time  Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        for (int i=0; i<m; i++)
            go(triangle, m-1, i, dp);
        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
private:
    int go(const vector<vector<int>> &tri, int i, int j, vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == 0)
            return dp[i][j] = tri[i][j];
        if (j == 0)
            return dp[i][j] = tri[i][j] + go(tri, i-1, 0, dp);
        if (j == i)
            return dp[i][j] = tri[i][j] + go(tri, i-1, j-1, dp);

        return dp[i][j] = tri[i][j] + min(go(tri, i-1, j-1, dp), go(tri, i-1, j, dp));
    }
};

// Dynamic Programming
// Time  Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        for (int i=1; i<m; i++)
        {
            triangle[i][0] += triangle[i-1][0];
            triangle[i][i] += triangle[i-1][i-1];

            for (int j=1; j<i; j++)
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
        }
        return *min_element(triangle[m-1].begin(), triangle[m-1].end());
    }
};

int main()
{

    return 0;
}











