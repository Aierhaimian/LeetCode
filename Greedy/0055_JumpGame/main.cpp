#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 从数组第一个位置开始，数组中每个元素代表在该位置可以跳跃的最大长度
// 题目要求是否能够跳到数组的最后一个元素
// 可以变为求在数组中可以跳到的最大位置，如果此位置小于数组最后一个元素的
// 位置，则false，反之则true。
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        for (int i=0; i<nums.size(); i++) {
            if (i > maxIndex)
                return false;
            maxIndex = max(maxIndex, i+nums[i]);
        }
        return true;
    }
};

int main()
{

    return 0;
}

