#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1; // 在[l...r]的区间内二分查找
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (target == nums[mid])
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};

int main()
{

    return 0;
}

