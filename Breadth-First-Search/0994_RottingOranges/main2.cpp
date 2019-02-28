// BFS
// Time  Complexity: O(n)
// Space Complexity: O(n)
#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

class Solution {
private:
    int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        assert(grid.size() && grid[0].size());
        m = grid.size();
        n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j] == 1)
                    fresh ++;
                else if (grid[i][j] == 2)
                    q.push(make_pair(i*n+j, 0));

        int res = 0;

        while(q.empty() != true) {
            int cur = q.front().first;
            int time = q.front().second;
            q.pop();

            //res = max(res, step);
            res = time;

            int x = cur/n;
            int y = cur%n;
            for (int i=0; i<4; i++) {
                int nextx = x + d[i][0];
                int nexty = y + d[i][1];
                if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && grid[nextx][nexty] == 1) {
                    grid[nextx][nexty] = 2;
                    q.push(make_pair(nextx*n+nexty, time+1));
                }
            }
        }

        if (!allRotten(grid))
            return -1;
        return res;
    }
private:
    bool allRotten(const vector<vector<int>>& grid) {
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j] == 1)
                    return false;
        return true;
    }
};

int main()
{
        vector<vector<int>> grid1 = {
            {2,1,1},
            {1,1,0},
            {0,1,1}
    };
    cout << Solution().orangesRotting(grid1) << endl;
    // 4

    vector<vector<int>> grid2 = {
            {0, 0},
            {0, 0}
    };
    cout << Solution().orangesRotting(grid2) << endl;
    // 0

    vector<vector<int>> grid3 = {
            {1}
    };
    cout << Solution().orangesRotting(grid3) << endl;
    // -1
    return 0;
}

