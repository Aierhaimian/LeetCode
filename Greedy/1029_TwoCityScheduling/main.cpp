#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 2N个人去A/B两个城市面试
// 已知每个人分别取两个城市的代价
// 求在每个城市各去N个人的情况下的最小代价
// 
// Greedy
// Time  Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<vector<int>> A, B;
        int res = 0;
        for (const vector<int>& cost: costs) {
            if (cost[0] < cost[1])
                res += cost[0], A.push_back(cost);
            else
                res += cost[1], B.push_back(cost);
        }

        vector<vector<int>> &t = A.size() < B.size() ? B : A;

        sort(t.begin(), t.end(), [](const vector<int> &v1, const vector<int> &v2){
            return abs(v1[0] - v1[1]) > abs(v2[0] - v2[1]);
        });

        while (t.size() > costs.size() / 2) {
            res += abs(t.back()[0] - t.back()[1]);
            t.pop_back();
        }
        return res;
    }
};

int main()
{

    return 0;
}

