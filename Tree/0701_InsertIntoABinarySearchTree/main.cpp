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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return generateBST(root, val);
    }
private:
    TreeNode* generateBST(TreeNode* root, int val) {
        if (root == NULL) {
            root = new TreeNode(val);
            return root;
        }

        TreeNode *node = new TreeNode(val);
        TreeNode *p = root;
        while (p != NULL) {
            if (val > p->val) {
                if (p->right == NULL) {
                    p->right = new TreeNode(val);
                    return root;
                }
                p = p->right;
            }
            else {
                if (p->left == NULL) {
                    p->left = new TreeNode(val);
                    return root;
                }
                p = p->left;
            }
        }
        return root;
    }
};

int main()
{

    return 0;
}

