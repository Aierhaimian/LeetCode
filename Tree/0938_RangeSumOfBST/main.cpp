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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        if (root == NULL) return sum;

        generateSum(root, sum, L, R);

        return sum;
    }
private:
    void generateSum(TreeNode *root, int &sum, int L, int R) {
        if (root == NULL)
            return;

        if (root->val >= L && root->val <= R)
            sum += root->val;

        generateSum(root->left, sum, L, R);
        generateSum(root->right, sum, L, R);
    }
};

int main()
{

    return 0;
}

