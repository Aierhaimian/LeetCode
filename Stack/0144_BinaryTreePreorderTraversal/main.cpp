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
    vector<int> preorderTraversal(TreeNode* root) {
        res.clear();
        if (!root) return res;
        generatePreorder(root);
        return res;
    }
private:
    vector<int> res;

    void generatePreorder(TreeNode *root) {
        if (!root) return;

        res.push_back(root->val);

        generatePreorder(root->left);
        generatePreorder(root->right);
    }
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            res.push_back(cur->val);

            if (cur->right)
                s.push(cur->right);
            if (cur->left)
                s.push(cur->left);
        }

        return res;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> s;
        TreeNode *cur = root;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                res.push_back(cur->val);
                cur = cur->left;
            }

            if (!s.empty()) {
                cur = s.top();
                s.pop();
                cur = cur->right;
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}

