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

// 采用中序遍历，可以以升序的顺序访问树中节点
// 将所有节点之和减去该节点的值，就是这个节点对应的值
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        inOrderSum(root, sum);
        cout << sum << endl;

        inOrderGst(root, sum, 0);

        return root;
    }
private:
    void inOrderSum(TreeNode* root, int &sum) {
        if (root == NULL)
            return;
        inOrderSum(root->left, sum);
        sum += root->val;
        inOrderSum(root->right, sum);
    }

    void inOrderGst(TreeNode* root, int &sum, int value) {
        if (root == NULL)
            return;
        inOrderGst(root->left, sum, value);
        value = root->val;
        root->val = sum;
        cout << value << " : " <<sum << endl;
        sum -= value;
        inOrderGst(root->right, sum, value);
    }
};

int main()
{

    return 0;
}

