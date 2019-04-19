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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int curD = 0, curX = 0, curY = 0;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        int i = 1;
        while (i <= n*n) {
            if (!visited[curX][curY]) {
                matrix[curX][curY] = i;
                visited[curX][curY] = true;
                i++;
            }

            int nextX = curX + d[curD][0];
            int nextY = curY + d[curD][1];
            if (isArea(n, nextX, nextY) && !visited[nextX][nextY]) {
                curX = nextX;
                curY = nextY;
            }
            else
                curD = (curD + 1) % 4;
        }
        return matrix;
    }
private:
    int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

    bool isArea(int n, int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
};

void print_vec(const vector<vector<int>>& matrix){
    for(vector<int> v: matrix) {
        for (int e: v)
            cout << e << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    print_vec(Solution().generateMatrix(6));

    return 0;
}

