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
class Solution1 {
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


// 我自己写的方法：双指针法
// Time  Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) // fixed bug1: add corner case
            return true;
        int i = nums.size()-2;
        int j = nums.size()-1;
        bool flag = false;
        while (i >= 0) { // fixed bug2: i > 0 -> i >= 0
            if (nums[i] >= j-i) { // fixed bug3: nums[i] > j-i -> nums[i] >= j-i
                flag = true;
                j = i;
                -- i;
            }
            else {
                flag = false;
                -- i;
            }
        }
        if (flag == false)
            return false;
        return true;
    }
};

int main()
{

    return 0;
}

