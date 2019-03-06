#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
// In Order traversal and link during the traversal
// Time  Complexity: O(n)
// Space Complexity: O(n) where h is the height of the tree
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL)
            return NULL;

        TreeNode* tail;
        return inOrder(root, tail);
    }
private:
    TreeNode* inOrder(TreeNode *node, TreeNode* &tail) {
        if (node->left == NULL && node->right == NULL) {
            tail = node;
            return node;
        }

        TreeNode *ret;
        if (node->left) {
            ret = inOrder(node->left, tail);
            tail->left = NULL;
            tail->right = node;
        }
        else
            ret = node;

        node->left = NULL;
        tail = node;

        if (node->right) {
            TreeNode *root = inOrder(node->right, tail);
            node->right = root;
        }

        return ret;
    }
};

int main()
{
    return 0;
}

