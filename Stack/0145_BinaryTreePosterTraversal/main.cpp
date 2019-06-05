#include <iostream>
#include <vector>
#include <stack>
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

class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        res.clear();
        genratePostor(root);
        return res;
    }
private:
    vector<int> res;
    void genratePostor(TreeNode *root) {
        if (!root)
            return;
        genratePostor(root->left);
        genratePostor(root->right);
        res.push_back(root->val);
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> s;
        TreeNode *cur;
        TreeNode *pre = NULL;
        s.push(root);
        while (!s.empty()) {
            cur = s.top();
            if ((cur->left == NULL && cur->right == NULL) || (pre && (cur->left == pre || cur->right == pre))) {
                res.push_back(cur->val);
                s.pop();
                pre = cur;
            }
            else {
                if (cur->right)
                    s.push(cur->right);
                if (cur->left)
                    s.push(cur->left);
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}

