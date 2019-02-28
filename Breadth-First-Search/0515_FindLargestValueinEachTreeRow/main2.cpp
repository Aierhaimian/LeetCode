// DFS
// Time  Complexity: O(n)
// Space Complexity: O(n)
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

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;

        dfs(root, res, 1);
        return res;
    }
private:
    void dfs(TreeNode* root, vector<int> &vec, size_t depth) {
        if (root == NULL) return;

        if (vec.size() < depth)
            vec.push_back(root->val);
        else
            vec[depth - 1] = max(root->val, vec[depth - 1]);

        dfs(root->left, vec, depth + 1);
        dfs(root->right, vec, depth + 1);
    }
};

int main() {
    return 0;
}
