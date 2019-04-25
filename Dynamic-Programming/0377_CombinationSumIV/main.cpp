#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Recursive
// Time  Complexity: O(nums_size * target)
// Space Complexity: O(1)
class Solution1 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        return findCombination(nums, target);
    }
private:
    int findCombination(const vector<int> &nums, int target) {
        if (target == 0) return 1;

        int res = 0;
        for (int num: nums)
            if (target >= num)
                res += findCombination(nums, target - num);
        return res;
    }
};

// Memory Search
// Time  Complexity: O(nums_size * target)
// Space Complexity: O(target)
class Solution2 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        memo = vector<int>(target+1, -1);
        return findCombination(nums, target);
    }
private:
    vector<int> memo;
    int findCombination(const vector<int> &nums, int target) {
        if (target == 0) return 1;

        if (memo[target] != -1) return memo[target];

        int res = 0;
        for (int num: nums)
            if (target >= num)
                res += findCombination(nums, target - num);
        return memo[target] = res;
    }
};

// Dynamic Programming
// Time  Complexity: O(nums_size * amount)
// Space Complexity: O(target)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> memo(target+1, 0);

        memo[0] = 1;

        for (int i=1; i<=target; i++)
            for (int j=0; j< n; j++) {
                if (nums[j] <= i) {
                    if (memo[i] == -1 || memo[i-nums[j]] == -1 ||
                        (long long)memo[i] + (long long)memo[i-nums[j]] > INT_MAX)
                        memo[i] = -1;
                    else
                        memo[i] += memo[i-nums[j]];
                }
            }
        assert(memo[target] != -1);
        return memo[target];
    }
};

int main()
{
    vector<int> arr1 = {1,2,3};
    int tgt1 = 4;
    cout << Solution().combinationSum4(arr1, tgt1) << endl;
    return 0;
}

