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
// Using Morris Traversal
// Time  Complexity: O(n)
// Space Complexity: O(n) where h is the height of the tree
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL)
            return NULL;

        TreeNode* dummyRoot = new TreeNode(-1);
        cur = dummyRoot;

        TreeNode *node = root;
        while (node) {
            if (node->left == NULL) {
                cur->right = node;
                cur = cur->right;
                cur->left = NULL;

                node = node->right;
            }
            else {
                TreeNode *prev = node->left;
                while (prev->right && prev->right != node)
                    prev = prev->right;

                if (prev->right == NULL) {
                    prev->right = node;
                    node = node->left;
                }
                else {
                    prev->right = NULL;

                    cur->right = node;
                    cur = cur->right;
                    cur->left = NULL;

                    node = node->right;
                }
            }
        }

        TreeNode * ret = dummyRoot->right;
        delete dummyRoot;
        return ret;
    }
private:
    TreeNode *cur;
};

int main()
{
    return 0;
}

