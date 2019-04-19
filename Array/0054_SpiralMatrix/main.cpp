#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Simulation
// Time  Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        m = matrix.size();
        if (m == 0) return res;
        n = matrix[0].size();
        if (n == 0) return res;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int curD = 0, curX = 0, curY = 0;
        while (res.size() < m*n) {

            if (!visited[curX][curY]) {
                res.push_back(matrix[curX][curY]);
                visited[curX][curY] = true;
            }

            int nextX = curX + d[curD][0];
            int nextY = curY + d[curD][1];
            if (isArea(nextX, nextY) && !visited[nextX][nextY]) {
                curX = nextX;
                curY = nextY;
            }
            else
                curD = (curD + 1) % 4;
        }
        return res;
    }
private:
    int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int m,n;
    bool isArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};

void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main()
{
    vector<vector<int>> matrix1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    print_vec(Solution().spiralOrder(matrix1));

    return 0;
}

