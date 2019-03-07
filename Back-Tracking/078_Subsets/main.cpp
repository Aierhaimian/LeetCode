#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        currRes.clear();
        res.push_back(currRes);
        generateSubsets(nums, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> currRes;
    void generateSubsets(vector<int> &nums, size_t index) {
        size_t m = res.size();
        if(nums.size() < index+1)
            return;
        for(size_t i=0; i<m; i++) {
            vector<int> currRes = res[i];
            currRes.push_back(nums[index]);
            res.push_back(currRes);
        }
        generateSubsets(nums, index+1);
        return;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

