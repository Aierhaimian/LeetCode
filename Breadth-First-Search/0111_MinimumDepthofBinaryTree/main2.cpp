// DFS
// Time  Complexity: O(n)
// Space Complexity: O(n)
#include <iostream>
#include <climits>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;

        if (root->left == NULL && root->right == NULL)
            return 1;

        int res = INT_MAX;
        if (root->left != NULL)
            res = min(res, 1 + minDepth(root->left));
        if (root->right != NULL)
            res = min(res, 1 + minDepth(root->right));

        return res;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

