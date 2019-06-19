#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// https://leetcode.com/problems/largest-triangle-area/discuss/122711/C%2B%2BJavaPython-Solution-with-Explanation-and-Prove
// Aera = 1/2|AB * AC|
//      = 1/2|XaYb+XbYc+XcYa-XaYc-XcYb-XbYa|
// Time  Complexity: O(n^3)
// Space Complexity: O(1)
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        for (auto &i : points)
            for (auto &j : points)
                for (auto &k : points)
                    res = max(res, 0.5*abs(i[0]*j[1]+j[0]*k[1]+k[0]*i[1]-j[0]*i[1]-k[0]*j[1]-i[0]*k[1]));
        return res;
    }
};

int main()
{

    return 0;
}

