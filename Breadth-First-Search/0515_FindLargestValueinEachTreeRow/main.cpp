// BFS
// Time  Complexity: O(n)
// Space Complexity: O(n)
#include <iostream>
#include <vector>
#include <queue>

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

        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));

        int depth = 0;

        while(q.empty() != true) {
            TreeNode* w = q.front().first;
            int step = q.front().second;
            q.pop();

            if (depth < step) {
                depth = step;
                res.push_back(w->val);
            }
            else
                res[depth - 1] = max(res[depth - 1], w->val);

            if (w->left)
                q.push(make_pair(w->left, step + 1));

            if (w->right)
                q.push(make_pair(w->right, step + 1));
        }
        return res;
    }
};

int main() {
    return 0;
}
