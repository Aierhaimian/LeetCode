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
 
// In Order traversal and store all the nodes
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL)
            return NULL;

        vector<TreeNode*> nodes;
        inOrder(root, nodes);

        for (size_t i=1; i<nodes.size(); i++) {
            nodes[i - 1]->left = NULL;
            nodes[i - 1]->right = nodes[i];
        }
        nodes.back()->left = NULL;
        nodes.back()->right = NULL;

        return nodes[0];
    }
private:
    void inOrder(TreeNode *root, vector<TreeNode*> &nodes) {
        if (root == NULL)
            return;

        inOrder(root->left, nodes);
        nodes.push_back(root);
        inOrder(root->right, nodes);
    }
};

int main()
{
    return 0;
}

