// Recursive
// No need revert one child tree
// see if the two child trees of the root are mirror directly
// Time  Complexity: O(n)
// Space Complexity: O(n)
#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        :val(x), left(NULL), right(NULL)
    {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;

        TreeNode* left = root->left;
        TreeNode* right = root->right;


        return isMirror(left, right);
    }

private:
    bool isMirror(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
            return true;
        
        if (root1 == NULL || root2 == NULL)
            return false;

        if (root1->val != root2->val)
            return false;

        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

