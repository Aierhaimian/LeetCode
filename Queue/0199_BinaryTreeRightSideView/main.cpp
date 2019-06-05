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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        vector<vector<int>> tmp;
        queue<pair<TreeNode*, int>> que;
        que.push(make_pair(root, 0));
        while (!que.empty()) {
            TreeNode *cur = que.front().first;
            int level = que.front().second;
            que.pop();

            if (level == tmp.size())
                tmp.push_back(vector<int>());
            tmp[level].push_back(cur->val);

            if (cur->left)
                que.push(make_pair(cur->left, level + 1));
            if (cur->right)
                que.push(make_pair(cur->right, level + 1));
        }

        for (int i=0; i<tmp.size(); i++) {
            res.push_back(tmp[i].back());
        }
        return res;
    }
};

int main()
{

    return 0;
}

