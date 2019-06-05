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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;

        generateInvert(root);

        return root;
    }
private:
    void generateInvert(TreeNode* root) {
        if (!root) return;
        swap(root->left, root->right);

        generateInvert(root->left);
        generateInvert(root->right);
    }
};

int main()
{

    return 0;
}

