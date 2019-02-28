// BFS
// Time  Complexity: O()
// Space Complexity: O()
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty()) return board;
        size_t m = board.size();
        size_t n = board[0].size();

        // Eight adjacent points
        // (-1, -1) (-1, 0) (-1, 1)
        // ( 0, -1) ( 0, 0) ( 0, 1)
        // ( 1, -1) ( 1, 0) ( 1, 1)
        vector<vector<int>> dirs = {{-1,-1}, {-1,0}, {-1,1},
                                    { 0,-1},         { 0,1},
                                    { 1,-1}, { 1,0}, { 1,1}};
        queue<pair<int, int>> q;
        if (board[click[0]][click[1]] != 'M')
            q.emplace(click[0], click[1]);
        else
            board[click[0]][click[1]] = 'X';

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            int mines = 0;
            vector<pair<int,int>> tmp;

            // ignore already handled point
            if (board[curr.first][curr.second] != 'E') continue;

            // traverse eight adjcent points to find mines
            for (auto d: dirs) {
                size_t x = curr.first + d[0];
                size_t y = curr.second + d[1];

                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (board[x][y] == 'M')
                        mines ++;
                    tmp.emplace_back(x, y);
                }
            }

            if (mines) {
                board[curr.first][curr.second] = '0' + mines;
            }
            else {
                board[curr.first][curr.second] = 'B';
                // No mine, then save eight adjcent points for next iteration
                for (auto e: tmp) {
                    q.emplace(e);
                }
            }
        }
        return board;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

