#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        tryColor(grid, r0, c0);

        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (!isBorder(grid, i, j))
                    visited[i][j] = false;

        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++) {
                if (visited[i][j] == true)
                    grid[i][j] = color;
            }
        return grid;
    }
private:
    int m, n;
    int d[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<vector<bool>> visited;

    void tryColor(const vector<vector<int>> &grid, int r, int c) {
        // if (r < 0 || r > m-1 || c < 0 || c > n - 1) return;
        visited[r][c] = true;

        for (int i=0 ; i<4; i++) {
            int newX = r + d[i][0];
            int newY = c + d[i][1];
            if (isArea(newX, newY) && grid[newX][newY] == grid[r][c] && !visited[newX][newY]) {
                tryColor(grid, newX, newY);
            }
        }
        return;
    }
    bool isArea(int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
    bool isBorder(const vector<vector<int>> &grid, int r, int c) {
        if (r == 0 || r == m-1 || c == 0 || c == n-1)
            return true;
        for (int i=0; i<4; i++) {
            int newX = r + d[i][0];
            int newY = c + d[i][1];
            if (isArea(newX,newY) && grid[r][c] != grid[newX][newY])
                return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}

