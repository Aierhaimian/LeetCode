// BFS
// Using one queue to level traverse the root in different directions
// Time  Complexity: O(n)
// Space Complexity: O(n)
#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        :val(x), left(NULL), right(NULL)
    {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;

        queue<TreeNode*> q;
        q.push(root);
        q.push(root);

        while(!q.empty()) {
            TreeNode* node1 = q.front();
            q.pop();

            TreeNode* node2 = q.front();
            q.pop();

            if (node1 == NULL && node2 == NULL)
                continue;
            if (node1 == NULL || node2 == NULL)
                return false;
            if (node1->val != node2->val)
                return false;

            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

