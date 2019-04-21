#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 在一个R行C列的矩阵里，求元素(r0,c0)到其他
// 元素的曼哈顿距离，并输出距离由短到长的排序
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;

        multimap<int, vector<int>> record;
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                int distance = abs(i-r0) + abs(j-c0);
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                record.insert(pair<int, vector<int>>(distance, tmp));
            }
        }
        for (auto iter = record.begin(); iter != record.end(); iter++)
            res.push_back(iter->second);
        return res;
    }
};

int main()
{

    return 0;
}

