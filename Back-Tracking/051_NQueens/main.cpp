#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        col = vector<bool>(n, false);
        dial1 = vector<bool>(2*n-1, false);
        dial2 = vector<bool>(2*n-1, false);

        vector<int> row;
        putQueen(n, 0, row);
        return res;
    }
private:
    vector<vector<string>> res;
    vector<bool> col, dial1, dial2;
    // 尝试在一个n皇后问题中，摆放第index行的皇后位置
    void putQueen(int n, int index, vector<int> &row) {
        if (index == n) {
            res.push_back(generateBoard(n, row));
            return;
        }

        for (int i=0; i<n; i++) {
            // 尝试将第Index行的皇后摆放在第i列
            if (!col[i] && !dial1[index+i] && !dial2[index-i+n-1]) {
                row.push_back(i);
                col[i] = true;
                dial1[index+i] = true;
                dial2[index-i+n-1] = true;
                putQueen(n, index+1, row);
                col[i] = false;
                dial1[index+i] = false;
                dial2[index-i+n-1] = false;
                row.pop_back();
            }
        }

        return;
    }

    vector<string> generateBoard(int n, vector<int> &row) {
        assert(row.size() == n);
        vector<string> board(n, string(n, '.'));
        for(int i=0; i<n; i++)
            board[i][row[i]] = 'Q';
        return board;
    }

};

int main()
{
    int n = 8;
    vector<vector<string>> vec = Solution().solveNQueens(n);
    for(vector<string> b: vec)
    {
        for(string s: b)
            cout << s << endl;
        cout << endl;
    }

    return 0;
}

