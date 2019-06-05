#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<pair<TreeNode*, int>> que;
        que.push(make_pair(root, 0));
        while (!que.empty()) {
            TreeNode *cur = que.front().first;
            int level = que.front().second;
            que.pop();

            if (level == res.size())
                res.push_back(vector<int>());
            res[level].push_back(cur->val);

            if (cur->left)
                que.push(make_pair(cur->left, level + 1));
            if (cur->right)
                que.push(make_pair(cur->right, level + 1));
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{

    return 0;
}

