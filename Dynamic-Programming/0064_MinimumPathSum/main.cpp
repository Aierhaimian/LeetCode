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
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();

        int mini = INT_MAX;
        miniSum(grid, 0, 0, 0, mini);

        return mini;
    }
private:
    int m, n;
    void miniSum(const vector<vector<int>> &grid, int x, int y, int sum, int &mini)
    {

        sum += grid[x][y];

        if (x+1 == m && y+1 == n)
        {
            // cout << sum << endl;
            mini = min(mini, sum);
            return;
        }


        if (x+1 < m && y+1 == n)
            miniSum(grid, x+1, y, sum, mini);
        else if (x+1 == m && y+1 < n)
            miniSum(grid, x, y+1, sum, mini);
        else if (x+1 < m && y+1 < n)
        {
            miniSum(grid, x, y+1, sum, mini);
            miniSum(grid, x+1, y, sum, mini);
        }

        return;
    }
};

// Dynamic Programming
// Time  Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution2 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        vector<vector<int>> res = grid;

        for (int j=1; j<n; j++)
            res[0][j] += res[0][j-1];

        for (int i=1; i<m; i++)
            res[i][0] += res[i-1][0];

        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
                res[i][j] += min(res[i-1][j], res[i][j-1]);
        return res[m-1][n-1];
    }
};

// Dynamic Programming
// Time  Complexity: O(n^2)
// Space Complexity: O(n) -> n
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        vector<int> res(n, 0);
        res[0] = grid[0][0];

        for (int j=1; j<n; j++)
            res[j] = grid[0][j] + res[j-1];
        for (int i=1; i<m; i++)
        {
            res[0] += grid[i][0];
            for (int j=1; j<n; j++)
                res[j] = grid[i][j] + min(res[j], res[j-1]);
        }
        return res[n-1];
    }
};

int main()
{
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};

    cout << Solution().minPathSum(grid) << endl;

    return 0;
}

