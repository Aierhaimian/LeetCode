#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 考虑偷取 [x...n-1] 范围里的房子

class Solution1 {
public:
    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        return tryRob(nums, 0);
    }
private:
    // memo[i] 表示考虑抢劫 nums[i ... n) 所能获得的最大收益
    vector<int> memo;

    // 考虑抢劫 nums[index ... nums.size()) 这个范围的所有房子
    int tryRob(vector<int> &nums, int index) {
        if (index >= nums.size())
            return 0;

        if (memo[index] != -1) return memo[index];

        int res = 0;
        for (int i=index; i<nums.size(); i++)
            res = max(res, nums[i] + tryRob(nums, i + 2) );

        memo[index] = res;

        return res;
    }
};

class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // memo[i] 表示考虑抢劫 nums[i ... n-1] 所能获得的最大收益
        vector<int> memo(n, -1);

        memo[n-1] = nums[n-1];
        for (int i=n-2; i>=0; i--)
        {
            // memo[i]
            for (int j=i; j<n; j++)
                memo[i] = max(memo[i], nums[j] + ((j+2) < n ? memo[j+2] : 0) );
        }
        return memo[0];
    }
};

/*-------------------------------------------------------------------------------------*/
// 考虑偷取 [0...x] 范围里的房子

class Solution3 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        memo = vector<int>(n, -1);
        return tryRob(nums, n-1);
    }
private:
    vector<int> memo;
    int tryRob(vector<int>& nums, int index) {
        if (index < 0) return 0;

        if (memo[index] != -1) return memo[index];

        int res = 0;
        for (int i=index; i>=0; i--)
            res = max(res, nums[i] + tryRob(nums, i - 2));

        memo[index] = res;

        return res;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> memo(n, -1);

        memo[0] = nums[0];

        for (int i=1; i<n; i++)
            for (int j = i; j>=0; j--)
                memo[i] = max(memo[i], nums[j] + (j-2 >= 0 ? memo[j-2] : 0) );
        return memo[n-1];
    }
};


int main()
{
    vector<int> nums1 = {1,2,3,1};
    cout << Solution().rob(nums1) << endl;

    vector<int> nums2 = {0};
    cout << Solution().rob(nums2) << endl;
    return 0;
}

