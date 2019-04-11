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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* p = root;
        if (!p) return p;

        if (p->val == val) return p;

        TreeNode *left = searchBST(p->left, val);
        TreeNode *right = searchBST(p->right, val);

        return left ? left : right;
    }
};

int main()
{

    return 0;
}

