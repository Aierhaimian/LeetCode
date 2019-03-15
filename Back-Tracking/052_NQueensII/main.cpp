#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        res = 0;
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2*n-1, false);
        dia2 = vector<bool>(2*n-1, false);

        vector<int> row;
        putQueen(n, 0, row);

        return res;
    }
private:
    vector<bool> col, dia1, dia2;
    int res;
    void putQueen(int n, int index, vector<int> &row) {
        if(index == n) {
            res ++;
            return;
        }

        for(int i=0; i<n; i++) {
            if(!col[i] && !dia1[index+i] && !dia2[index-i+n-1]) {
                row.push_back(i);
                col[i] = true;
                dia1[index+i] = true;
                dia2[index-i+n-1] = true;
                putQueen(n, index+1, row);
                col[i] = false;
                dia1[index+i] = false;
                dia2[index-i+n-1] = false;
                row.pop_back();
            }
        }

        return;
    }
};

int main()
{
    int n = 8;
    int res = Solution().totalNQueens(n);
    cout << res << endl;
    return 0;
}

