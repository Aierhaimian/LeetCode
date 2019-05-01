#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Sorting + Two Pointer
// Time  Complexity: O(nlogn) + O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        assert(nums.size() >= 3);

        sort(nums.begin(), nums.end());

        int diff = abs(nums[0] + nums[1] + nums[2] - target); // 初始差值
        int res = nums[0] + nums[1] + nums[2]; // 初始结果

        for (int i=0; i<nums.size(); i++) {
            int l = i+1, r = nums.size()-1;
            int t = target - nums[i];
            while (l < r) {
                if (nums[l] + nums[r] == t)
                    return nums[i] + nums[l] + nums[r]; // 差值最小，为0
                else {
                    if (abs(nums[l] + nums[r] - t) < diff) {
                        diff = abs(nums[l] + nums[r] -t); // 更新差值
                        res = nums[i] + nums[l] + nums[r]; // 更新结果
                    }

                    if (nums[l] + nums[r] < t) // res小于target，增加l
                        l++;
                    else                       // 否则减小r
                        r--;
                }
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}

