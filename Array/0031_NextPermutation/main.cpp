#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

/*
* 链接：https://leetcode-cn.com/problems/next-permutation
*
* 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
* 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
* 必须原地修改，只允许使用额外常数空间。
* 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
*
* 1,2,3 → 1,3,2
* 3,2,1 → 1,2,3
* 1,1,5 → 1,5,1
 */

// https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
// From wikipedia
// 1. Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists(k<0), just reverse nums and done.
// 2. Find the largest index l > k such that nums[k] < nums[l].
// 3. Swap nums[k] and nums[l].
// 4. Reverse the sub-array nums[k + 1:].
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k, l;
        for (k = n-2; k>=0; k--) {
            if (nums[k] < nums[k+1]) {
                break;
            }
        }
        if (k < 0) {
            reverse(nums.begin(), nums.end()); // rule one
        }
        else {
            for (l = n-1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            }
            swap(nums[l], nums[k]);
            reverse(nums.begin()+(k+1), nums.end());
        }
    }
};

int main()
{
    vector<int> vec = {1, 2, 3};
    Solution().nextPermutation(vec);
    
    for (int i: vec)
        cout << i << " ";
    cout << endl;
    return 0;
}

