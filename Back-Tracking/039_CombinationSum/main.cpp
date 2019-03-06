#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        generateRes(candidates, target, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> subRes;
    void generateRes(vector<int> &candidates, int target, size_t index)
    {
        if(target == 0){
            res.push_back(subRes);
            return;
        }

        for(size_t i=index; i<candidates.size(); i++) {
            if(target >= candidates[i]) {
                subRes.push_back(candidates[i]);
                generateRes(candidates, target - candidates[i], i);
                subRes.pop_back();
            }
        }
        return;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

