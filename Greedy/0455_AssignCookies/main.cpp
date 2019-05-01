#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Greedy
// Time  Complexity: O(nlogn) + O(n)
// Space Complexity: O(1)
class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        // 从大到小排序
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        int si = 0, gi = 0;
        int res = 0;
        while (gi < g.size() && si < s.size()) {
            if (s[si] >= g[gi]) {
                res ++;
                si ++;
                gi ++;
            }
            else {
                gi ++; // 当前的饼干满足不了当前的人，尝试分配给下一个
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}

