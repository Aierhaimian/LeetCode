#include <iostream>
#include <vector>

using namespace std;

// 首先找到R的位置
// 其次让R移动，同时记录吃掉的p数
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int RookPos = -1;
        for (int i=0; i<64; i++)
            if (board[i/8][i%8] == 'R') {
                RookPos = i;
                break;
            }
        assert(RookPos != -1);

        for (int i=0; i<4; i++) {
            for (int k=1; ; k++) {
                int newX = RookPos/8 + k*d[i][0];
                int newY = RookPos%8 + k*d[i][1];
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
    int res;

    bool isArea(int x, int y) {
        if (x >= 0 && x < 8 && y >= 0 && y < 8)
            return true;
        return false;
    }

};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

