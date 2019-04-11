#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>


// Using quick sort partition
// Time  Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;

        recursive(nums, l, r, nums.size() - k + 1);

        return res;
    }
private:
    int res = -1;
    void recursive(vector<int> &nums, int l, int r, int k)
    {
        if (l >= r)
        {
            res = nums[l];
            return;
        }

        int p = partition(nums, l, r);

        if ((p + 1) == k)
        {
            res = nums[p];
            return;
        }
        else if ((p + 1) < k)
            recursive(nums, p+1, r, k);
        else
            recursive(nums, l, p-1, k);
    }

    int partition(vector<int> &nums, int l, int r)
    {
        int pivot = nums[r];
        int i = l;

        for (int j=l; j<r; j++)
        {
            if (nums[j] < pivot)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }
};

int main()
{

    return 0;
}

