#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Brute Force
// Time  Complexity: O(n^2)
// Space Complexity: O(1)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        if (n < 2) return res;

        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }
};

// Using hash-table
// for every nums[i], we find target = nums[i]
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        if (n < 2) return res;

        unordered_map<int, int> record;
        for (int i=0; i<n; i++)
            record[nums[i]] = i;

        for (int i=0; i<n; i++) {
            if (record.find(target - nums[i]) != record.end() &&
                record[target - nums[i]] != i) {
                res.push_back(i);
                res.push_back(record[target-nums[i]]);
                break;
            }
        }
        return res;
    }
};

// The Big Brothor on LeetCode Solution
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) return {};

        unordered_map<int, int> record;
        for (int i=0; i<nums.size(); i++) {
            int complement = target - nums[i];
            if (record.find(complement) != record.end())
                return {record[complement], i};
            record[nums[i]] = i;
        }
        return {};
    }
};

 
// Two pointer
// Time  Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.size() < 2) return res;

        vector<int> pos(nums);
        sort(pos.begin(), pos.end());

        int i = 0;
        int j = pos.size() - 1;
        while (i < j) {
            if (pos[i] + pos[j] < target)
                ++ i;
            else if (pos[i] + pos[j] > target)
                -- j;
            else
                break;
        }

        for (int k=0; k<nums.size(); ++k) {
            if (nums[k] == pos[i]) {
                res.push_back(k);
                continue;
            }
            if (nums[k] == pos[j]) {
                res.push_back(k);
                continue;
            }
        }
        return res;
    }       
};

int main()
{

    return 0;
}

