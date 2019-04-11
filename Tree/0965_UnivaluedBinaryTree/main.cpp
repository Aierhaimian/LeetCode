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
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        int val = root->val;

        return preOrder(root, val);

    }
private:
    bool preOrder(TreeNode *r, int val)
    {
        if (!r) return true;
        if (r != NULL && r->val != val)
            return false;
        bool left = preOrder(r->left, val);
        bool right = preOrder(r->right, val);

        return left & right;
    }
};

int main()
{

    return 0;
}

