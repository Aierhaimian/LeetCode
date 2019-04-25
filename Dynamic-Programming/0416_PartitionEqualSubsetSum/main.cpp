#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Recursive
// Time  Complexity: O(2^n)
// Space Complexity: O(1)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            assert(nums[i] > 0);
            sum += nums[i];
        }

        if (sum%2 != 0) return false;

        return tryPartition(nums, nums.size()-1, sum/2);
    }
private:
    // 使用[0...index]，是否可以完全填充一个容量为sum的背包
    bool tryPartition(const vector<int> &nums, int index, int sum) {
        if (sum == 0)
            return true;

        if (sum <0 || index <0)
            return false;

        return tryPartition(nums, index-1, sum) ||
            tryPartition(nums, index-1, sum - nums[index]);
    }
};

// Memory Search
// Time  Complexity: O(n*sum)
// Space Complexity: O(n*sum)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            assert(nums[i] > 0);
            sum += nums[i];
        }

        if (sum%2 != 0) return false;

        memo = vector<vector<int>>(nums.size(), vector<int>(sum/2+1, -1));

        return tryPartition(nums, nums.size()-1, sum/2);
    }
private:
    // memo[i][c] 表示索引为[0...i]的这些元素，
    // 是否可以完全填充一个容量为C的背包
    // -1表示未计算；0表示不可以填充；1表示可以填充
    vector<vector<int>> memo;
    // 使用[0...index]，是否可以完全填充一个容量为sum的背包
    bool tryPartition(const vector<int> &nums, int index, int sum) {
        if (sum == 0)
            return true;

        if (sum <0 || index <0)
            return false;

        if (memo[index][sum] != -1)
            return memo[index][sum] == 1;

        memo[index][sum] = 
            (tryPartition(nums, index-1, sum) ||
                tryPartition(nums, index-1, sum - nums[index])) ? 1 : 0;

        return memo[index][sum] == 1;
    }
};

// Dynamic Programming
// Time  Complexity: O(n*sum)
// Space Complexity: O(sum)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            assert(nums[i] > 0);
            sum += nums[i];
        }

        if (sum%2)
            return false;

        int n = nums.size();
        int C = sum/2;
        vector<bool> memo(C+1, false);

        for (int j=0; j<=C; j++)
            memo[j] = (nums[0] == j);

        for (int i=1; i<n; i++)
            for (int j=C; j>=nums[i]; j--)
                memo[j] = memo[j] || memo[j-nums[i]];

        return memo[C];
    }
};

int main()
{

    return 0;
}

