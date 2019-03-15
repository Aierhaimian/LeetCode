#include <iostream>
#include <vector>

using namespace std;

// 首先找到R的位置
// 其次让R移动，同时记录吃掉的p数
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        res = 0;
        m = board.size();
        if (m == 0)
            return 0;
        n = board[0].size();

        pair<int, int> RookPos(-1, -1);
        findRook(board, RookPos);
        if (RookPos.first == -1 && RookPos.second == -1)
            return 0;

        for (int i=0; i<4; i++) {
            for (int k=1; ; k++) {
                int newX = RookPos.first + k*d[i][0];
                int newY = RookPos.second + k*d[i][1];
                if (isArea(newX, newY)) {
                    if (board[newX][newY] == 'p') {
                        res ++;
                        break;
                    }
                    else if (board[newX][newY] == 'B')
                        break;
                }    
                else
                    break;
            }
        }
        return res;
    }
private:
    int d[4][2] = {{0,-1}, {1,0}, {0,1}, {-1,0}};
    int m, n;
    int res;

    void findRook(vector<vector<char>>& board, pair<int, int>& pos) {
        for (size_t i=0; i<board.size(); i++)
            for (size_t j=0; j<board[i].size(); j++)
            {
                if (board[i][j] == 'R') {
                    pos.first = i;
                    pos.second = j;

                    return;
                }
            }
        return;
    }

    bool isArea(int x, int y) {
        if (x >= 0 && x < m && y >= 0 && y < n)
            return true;
        return false;
    }

};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

