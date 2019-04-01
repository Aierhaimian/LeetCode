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

// Inorder Traversal
// Time  Complexity: O(n)
// Space Complexity: O(h) where h is the height of the BST
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int index = k;
        return dfs(root, index)->val;
    }
private:
    TreeNode *dfs(TreeNode *root, int& index)
    {
        if (root == NULL) return NULL;

        TreeNode *res = dfs(root->left, k, index);
        if (res) return res;

        index --;
        if (index == 0)
            return root;

        return dfs(root->right, k, index);
    }
};

int main()
{

    return 0;
}

