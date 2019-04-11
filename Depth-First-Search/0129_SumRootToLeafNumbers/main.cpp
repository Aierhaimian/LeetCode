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
    int sumNumbers(TreeNode* root) {

        if(!root) return 0;

        int res = 0;
        dfs(root, 0, res);
        return res;
    }

private:
    void dfs(TreeNode* node, int tnum, int& sum){

        tnum = tnum * 10 + node->val;

        if(!node->left && !node->right)
            sum += tnum;
        else{
            if(node->left)
                dfs(node->left, tnum, sum);
            if(node->right)
                dfs(node->right, tnum, sum);
        }
    }
};

int main()
{

    return 0;
}

