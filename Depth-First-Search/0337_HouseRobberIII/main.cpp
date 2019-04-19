#include <iostream>
#include <vector>
#include <map>
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

// Brute Force
// Time  Complexity: O(2^n)
// Space Complexity: O(h)
class Solution1 {
public:
    int rob(TreeNode* root) {
        return tryRob(root, true);
    }
private:
    int tryRob(TreeNode* root, bool include) {
        if (root == NULL) return 0;

        int res = tryRob(root->left, true) + tryRob(root->right, true);
        if (include)
            res = max(root->val + tryRob(root->left, false) + tryRob(root->right, false), res);

        return res;
    }
};

// Memory Search
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    int rob(TreeNode* root) {
        dp.clear();
        return tryRob(root, true);
    }
private:
    map<pair<TreeNode*, int>, int> dp;

    int tryRob(TreeNode* root, bool include) {
        if (root == NULL) return 0;

        pair<TreeNode*, int> p = make_pair(root, include);
        if (dp.find(p) != dp.end())
            return dp[p];

        int res = tryRob(root->left, true) + tryRob(root->right, true);
        if (include)
            res = max(root->val + tryRob(root->left, false) + tryRob(root->right, false), res);

        return dp[p] = res;
    }
};

// Redefine the recursive function and return a two-element array
// represent the include and exclude maximum result for robbing the node
//
// Time Complexity: O(n), where n is the nodes' number in the tree
// Space Complexity: O(1)
class Solution3 {
public:
    int rob(TreeNode* root) {
        vector<int> res = tryRob(root);
        return max(res[0], res[1]);
    }
private:
    vector<int> tryRob(TreeNode* root) {
        if (root == NULL)
            return vector<int>(2, 0);
        vector<int> resL = tryRob(root->left);
        vector<int> resR = tryRob(root->right);
        vector<int> res(2, 0);

        res[0] = resL[1] + resR[1];
        res[1] = max(res[0], root->val + resL[0] + resR[0]);

        return res;
    }
};

int main()
{

    return 0;
}

