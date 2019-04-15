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
    int maxAncestorDiff(TreeNode* root) {
        pair<int, int> maxNum = make_pair(root->val, 1);
        pair<int, int> minNum = make_pair(root->val, 1);

        maxMin(root, maxNum, minNum, 1);

        return maxADiff;
    }
private:
    int maxADiff = INT_MIN;

    void maxMin(TreeNode *root, pair<int, int> maxNum, pair<int, int> minNum,  int value)
    {
        if (!root)
        {
            maxADiff = max(maxADiff, abs(maxNum.first - minNum.first));
            return;
        }

        if (maxNum.first < root->val)
            maxNum = make_pair(root->val, value);
        else if (minNum.first > root->val)
            minNum = make_pair(root->val, value);

        maxMin(root->left, maxNum, minNum, value++);
        maxMin(root->right, maxNum, minNum, value++);

    }
};

int main()
{

    return 0;
}

