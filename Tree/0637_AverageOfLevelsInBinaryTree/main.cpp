#include <iostream>
#include <vector>
#include <deque>
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == NULL)
            return res;

        deque<TreeNode*> dq;
        dq.push_back(root);
        while(!dq.empty()) {
            int n = dq.size();
            double avr = 0;
            for (int i=0; i<n; i++) {
                TreeNode *cur = dq.front();
                avr += cur->val;
                dq.pop_front();
                if (cur->left)
                    dq.push_back(cur->left);
                if (cur->right)
                    dq.push_back(cur->right);
            }
            res.push_back(avr/n);
        }
        return res;
    }
};

int main()
{

    return 0;
}

