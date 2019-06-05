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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == NULL)
            return root;

        return genetateBST(root, L, R);
    }
private:
    TreeNode* genetateBST(TreeNode *root, int L, int R) {
        if (root == NULL)
            return NULL;
        if (root->val < L)
            return genetateBST(root->right, L, R);
        if (root->val > R)
            return genetateBST(root->left, L, R);

        root->left = genetateBST(root->left, L, R);
        root->right = genetateBST(root->right, L, R);
        return root;
    }
};

int main()
{

    return 0;
}

