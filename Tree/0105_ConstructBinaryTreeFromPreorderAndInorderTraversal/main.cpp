#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder) {
        int m = preOrder.size(), n = inOrder.size();
        if (m == 0 || n == 0)
            return NULL;
        return generateTree(preOrder, 0, m, inOrder, 0, n);
    }
private:
    TreeNode* generateTree(vector<int>& preOrder, int pre_start_idx, int pre_end_idx,
                           vector<int>& inOrder, int in_start_idx, int in_end_idx) {
        if (in_end_idx <= in_start_idx)
            return NULL;
        TreeNode* root = new TreeNode(preOrder[pre_start_idx]);

        // find root in in order
        int root_idx = in_start_idx;
        for (; root_idx < in_end_idx; root_idx++)
            if (inOrder[root_idx] == root->val)
                break;

        root->left = generateTree(preOrder, pre_start_idx+1, pre_start_idx+1+root_idx-in_start_idx,
                                  inOrder, in_start_idx, root_idx);
        root->right = generateTree(preOrder, pre_start_idx+1+root_idx-in_start_idx, pre_end_idx,
                                   inOrder, root_idx+1, in_end_idx);
        return root;
    }
};

int main()
{

    return 0;
}

