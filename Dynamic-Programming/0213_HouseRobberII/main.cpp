#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 因为现在房子是一个环，第1个和第n个房子是相连的，不能一起偷
// 因此可以考虑先偷取[1...n-1]，再偷取[2...n]
// 然后比较上述两种方案哪个更大就选哪个。
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> nums2(nums.begin()+1, nums.end());
        return max(tryRob(nums1), tryRob(nums2));
    }
private:
    int tryRob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> memo(n, -1);
        memo[n-1] = nums[n-1];

        for (int i=n-2; i>=0; i--)
            for (int j=i; j<n; j++)
                memo[i] = max(memo[i], nums[j] + (j+2<n ? memo[j+2] : 0));
        return memo[0];
    }
};

int main()
{

    return 0;
}

