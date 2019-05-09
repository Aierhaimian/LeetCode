#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 首先，找出并记录每一行、每一列的最大值
// 然后对于每一个grid[i][j]，其高度不能
// 超过该点所在行、列最大值中的最小值
// 并记录其增加的高度
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        vector<int> rowMax(m, 0);
        vector<int> colMax(n, 0);
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++) {
                if (rowMax[i] < grid[i][j])
                    rowMax[i] = grid[i][j];
                if (colMax[j] < grid[i][j])
                    colMax[j] = grid[i][j];
            }

        int sum = 0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++) {
                int tmp = min(rowMax[i], colMax[j]);
                if (grid[i][j] < tmp)
                    sum += tmp - grid[i][j];
            }

        return sum;
    }
};

int main()
{

    return 0;
}

