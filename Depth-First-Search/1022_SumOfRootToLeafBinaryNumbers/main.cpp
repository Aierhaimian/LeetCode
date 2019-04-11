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

// DFS
// Time  Complexity: O(n)
// Space Complexity: O(h)
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
private:
    int sum = 0;
    const int MOD = 1e9 + 7;

    void dfs(TreeNode *r, int num)
    {
        num = (2*num + r->val) % MOD;

        if (!r->left && !r->right)
        {
            sum = (sum + num) % MOD;
            return;
        }
        else
        {
            if (r->left)
                dfs(r->left, num);
            if (r->right)
                dfs(r->right, num);
        }
    }
};

int main()
{

    return 0;
}

