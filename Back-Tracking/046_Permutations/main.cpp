#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define DEBUG 1

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        if(nums.size() == 0)
            return res;
        used = vector<bool>(nums.size(), false);
        vector<int> p;
        generatePermute(nums, 0, p);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<bool> used;
    // p中保存了一个有index个元素的排列
    // 想这个排列的末尾添加第index+1个元素，获得一个有index+1个元素的排列
    void generatePermute(const vector<int> &nums, size_t index, vector<int> &p) {

#if DEBUG
        cout << index << ": ";
        for(auto i: p)
            cout << i << " ";
        cout << endl;
#endif

        if (index == nums.size()) {
            //保存p
            res.push_back(p);
#if DEBUG
            cout << "get ";
            for(auto i: p)
                cout << i << " ";
            cout << " , return" <<endl;
#endif
            return;
        }

        for(size_t i=0; i<nums.size(); i++) {
            if(used[i] != true) {
                // 将nums[i]添加在p中
                p.push_back(nums[i]);
                used[i] = true;
#if DEBUG
                cout << "i = " << i << endl;
                cout << "index: " << index << " use: ";
                for(auto i: p)
                    cout << i << " ";
                cout << endl;
#endif
                generatePermute(nums, index+1, p);
#if DEBUG
                cout << "pop_back: " << p.back() << ", used[" << i <<"] = false" << endl;
#endif
                p.pop_back();
                used[i] = false;
            }
#if DEBUG
            else {
                cout << "used[" << i << "] = " << used[i] << endl;
            }
#endif
        }
#if DEBUG
        cout <<"index: " << index << " complete, return" << endl;
#endif
        return;
    }
};

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = Solution().permute(nums);
    for(size_t i=0; i<res.size(); i++) {
        for(size_t j=0; j<res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

