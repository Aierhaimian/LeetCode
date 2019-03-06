#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 为什么？
        res.clear();
        generateRes(candidates, target, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> currRes;
    void generateRes(vector<int> &candidates, int target, size_t index)
    {
        if(target == 0) {
            res.push_back(currRes);
            return;
        }

        for(size_t i=index; i<candidates.size(); i++) {
            if(i > index && candidates[i] == candidates[i-1]) // 为什么？
                continue;
            if(target >= candidates[i]) {
                currRes.push_back(candidates[i]);
                generateRes(candidates, target - candidates[i], i+1);
                currRes.pop_back();
            }
        }

        return;
    }
};

void print_vec(const vector<int> &vec) {
    for(auto i: vec)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> res = Solution().combinationSum2(candidates, 8);
    for(const vector<int>& a_res: res)
        print_vec(a_res);

    return 0;
}

