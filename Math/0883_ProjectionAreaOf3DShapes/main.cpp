#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

//Time  Complexity: O(n^2)
//Space Complexity: O(1)
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size();
        assert(m > 0);
        int n = grid[0].size();
        assert(n > 0);

        int xy = 0, yz = 0, xz = 0;

        for (int i=0; i<m; i++)
        {
            int yzTmp = 0, xzTmp = 0;
            for (int j=0; j<n; j++)
            {
                if (grid[i][j] != 0) xy++;
                if (grid[j][i] > yzTmp) yzTmp = grid[j][i];
                if (grid[i][j] > xzTmp) xzTmp = grid[i][j];
            }
            yz += yzTmp;
            xz += xzTmp;
        }
        return xy + yz + xz;
    }
};

int main()
{

    return 0;
}

