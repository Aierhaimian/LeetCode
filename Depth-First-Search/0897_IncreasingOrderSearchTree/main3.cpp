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
// Using a class member TreeNode cur
// Time  Complexity: O(n)
// Space Complexity: O(n) where h is the height of the tree
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL)
            return NULL;

        TreeNode* dummyRoot = new TreeNode(-1);
        cur = dummyRoot;
        inOrder(root);

        TreeNode * ret = dummyRoot->right;
        delete dummyRoot;
        return ret;
    }
private:
    TreeNode *cur;
    void inOrder(TreeNode *node) {
        if (node == NULL)
            return;

        inOrder(node->left);

        cur->right = node;
        cur = cur->right;
        cur->left = NULL;

        inOrder(node->right);
    }
};

int main()
{
    return 0;
}

