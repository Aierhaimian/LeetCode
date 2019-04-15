#include <iostream>
#include <vector>
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leaf1, leaf2;
        dfs(root1, leaf1);
        dfs(root2, leaf2);
        return leaf1 == leaf2;
    }
private:
    void dfs(TreeNode *rt, vector<int> &leaf)
    {
        if (!rt) return;
        if (!rt->left && !rt->right)
        {
            leaf.push_back(rt->val);
            return;
        }

        dfs(rt->left, leaf);
        dfs(rt->right, leaf);
    }
};

int main()
{

    return 0;
}

