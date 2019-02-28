//这个重点复习
//Simulation method
//Time  Complexity: O(n)
//Space Complexity: O(n)
#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_set>

using namespace std;

class Solution {
private:
    // d: 用来计算与腐烂水果相邻的水果位置
    const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n; // 网格的长宽

public:
    int orangesRotting(vector<vector<int>>& grid) {
        assert(grid.size() && grid[0].size());
        m = grid.size();
        n = grid[0].size();

        vector<int> rotten; // 腐烂水果的位置
        int fresh = 0; // 新鲜水果的个数
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1)
                    fresh ++;
                else if (grid[i][j] == 2)
                    rotten.push_back(i * n + j);
            }
        }

        if (!rotten.size()) // 初始无腐烂水果
            return fresh ? -1 : 0;

        unordered_set<int> used;
        for (int e: rotten)
            used.insert(e);

        int res = 0;
        while (rotten.size()) {
            vector<int> newrotten;
            for (int e: rotten) {
                int x = e/n;
                int y = e%n; // 计算腐烂水果的位置
                for (int i=0; i<4; i++) {
                    int nextx = x + d[i][0];
                    int nexty = y + d[i][1]; // 计算将要腐烂的水果位置
                    if (nextx >= 0 && nextx < m && nexty >= 0 &&nexty < n && grid[nextx][nexty] == 1) {
                        grid[nextx][nexty] = 2; // 对应位置水果腐烂
                        newrotten.push_back(nextx*n + nexty); // 更新腐烂水果位置
                        used.insert(nextx*n + nexty);
                    }
                }
            }

            if (newrotten.size()) // 有新水果腐烂，时间加一
                res ++;
            rotten = newrotten;
        }

        if (!allRotten(grid)) // 所有水果都腐烂了吗？
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
        {0 ,0},
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

