#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// DFS
// Time  Complexity: O(max_blocks^2)
// Space Complexity: O(max_blocks^2)
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int, int>> blockset;
        for (const vector<int> &e: blocked)
            blockset.insert(make_pair(e[0], e[1]));

        set<pair<int, int>> visited;
        if (dfs(source[0], source[1], source[0], source[1], blockset, visited))
            return true;
        return visited.count(make_pair(target[0], target[1]));
    }
private:
    int d[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    bool dfs(int x, int y, int sx, int sy, set<pair<int, int>> &blockset, set<pair<int, int>> &visited) {
        visited.insert(make_pair(x, y));

        if (dis(x, y, sx, sy) > 200) // why doing this?
            return true;
        
        for (int i=0; i<4; i++) {
            int nextX = x + d[i][0];
            int nextY = y + d[i][1];
            pair<int, int> next = make_pair(nextX, nextY);
            if (isArea(nextX, nextY) && !blockset.count(next) && !visited.count(next))
                if (dfs(nextX, nextY, sx, sy, blockset, visited))
                    return true;
        }
        return false;
    }

    int dis (int x0, int y0, int x1, int y1) {
        return abs(x0-x1) + abs(y0-y1);
    }

    bool isArea(int x, int y) {
        return x >=0 && x < 1000000 && y >= 0 && y < 1000000;
    }
};

int main()
{

    return 0;
}

