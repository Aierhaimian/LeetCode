#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Flood Fill
// Time  Complexity: O(n*m)
// Space Complexity: O(n*m)
class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        m = A.size();
        if (m == 0) return 0;
        n = A[0].size();

        // 如果四周有陆地，将该陆地及与之相连的陆地都置位，因为这些陆地都可以接触到边界
        for (int i=0; i<m; i++)
        {
            if (A[i][0]) dfs(A, i, 0);
            if (A[i][n-1]) dfs(A, i, n-1);
        }

        for (int i=0; i<n; i++)
        {
            if (A[0][i]) dfs(A, 0, i);
            if (A[m-1][i]) dfs(A, m-1, i);
        }

        //处理了四周的陆地后，剩余未被置位的陆地就是内陆了，它们全部被海洋包围，复合输出条件，计数输出
        int res = 0;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (A[i][j] == 1)
                {
                    res += dfs(A, i, j);
                }
            }
        }
        return res;
    }
private:
    int d[4][2] = {{0,-1}, {1,0}, {0,1}, {-1,0}};
    int m, n;

    int dfs(vector<vector<int>> &A, int x, int y)
    {
        A[x][y] = 0; // 置位陆地
        int res = 1;

        for (int i=0; i<4; i++)
        {
            int newX = x + d[i][0];
            int newY = y + d[i][1];
            if (isArea(newX, newY) && A[newX][newY])
                res += dfs(A, newX, newY);
        }
        return res;
    }

    bool isArea(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};

int main()
{

    return 0;
}

