// BFS
// Time  Complexity: O(n)
// Space Complexity: O(n)
#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == NULL) return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));

        int res = root->val;
        int maxStep = 0;

        while (q.empty() != true) {
            TreeNode* w = q.front().first;
            int step = q.front().second;
            q.pop();

            if (!w->left && !w->right) {
                res = maxStep < step ? w->val : res;
                maxStep = max(maxStep, step);
            }
            else {
                if (w->left)
                    q.push(make_pair(w->left, step + 1));
                if (w->right)
                    q.push(make_pair(w->right, step + 1));
            }
        }
        return res;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

