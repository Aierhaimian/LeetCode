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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int m = inorder.size(), n = postorder.size();
        if (m == 0 || n == 0)
            return NULL;
        return createTree(inorder, 0, m,
                          postorder, 0, n);
    }
private:
    TreeNode* createTree(vector<int>& inorder, int in_start_idx, int in_end_idx,
                         vector<int>& postorder, int po_start_idx, int po_end_idx) {
        if (in_end_idx <= in_start_idx)
            return NULL;
        TreeNode* root = new TreeNode(postorder[po_end_idx-1]);

        // find root idx in inorder
        int root_idx = in_start_idx;
        for (; root_idx < in_end_idx; root_idx++)
            if (inorder[root_idx] == root->val)
                break;

        root->left = createTree(inorder, in_start_idx, root_idx,
                                postorder, po_start_idx, po_start_idx+root_idx-in_start_idx);
        root->right = createTree(inorder, root_idx+1, in_end_idx,
                                 postorder, po_start_idx+root_idx-in_start_idx, po_end_idx-1);
        return root;
    }
};

int main()
{

    return 0;
}

