#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n == 0) return res;

        res.push_back(nums);
        if (n == 1) return res;
        while (res[0] != res.back() || res.size() == 1) {
            int k, l;
            for (k = n-2; k>=0; k--) {
                if (nums[k] < nums[k+1])
                    break;
            }
            if (k < 0) {
                reverse(nums.begin(), nums.end());
                res.push_back(nums);
            }
            else {
                for (l=n-1; l>k; l--) {
                    if (nums[l] > nums[k])
                        break;
                }
                swap(nums[l], nums[k]);
                reverse(nums.begin()+k+1, nums.end());
                res.push_back(nums);
            }
        }
        res.pop_back();
        return res;
    }
};

int main()
{

    return 0;
}

