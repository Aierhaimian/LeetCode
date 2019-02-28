// DFS
// No recursive and using stack
// Time  Complexity: O(n)
// Space Complexity: O(n)
#include <iostream>
#include <stack>
#include <climits>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;

        stack<pair<TreeNode*, int>> s;
        s.push(make_pair(root, 1));

        int res = INT_MAX;

        while (s.empty() != true) {
            TreeNode* w = s.top().first;
            int step = s.top().second;
            s.pop();

            if (w->left == NULL && w->right == NULL)
                res = min(res, step);
            else {
                if (w->left)
                    s.push(make_pair(w->left, step + 1));
                if (w->right)
                    s.push(make_pair(w->right, step + 1));
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

