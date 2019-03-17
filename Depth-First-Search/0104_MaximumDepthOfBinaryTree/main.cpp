#include <iostream>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
// DFS Recursive
// Time  Complexity: O(n), where n is the nodes' number in the tree
// Space Complexity: O(h), where h is the height of the tree
/*
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};*/

class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int depthL = 0;
        int depthR = 0;
        if (root->left)
            depthL = 1 + maxDepth(root->left);
        if (root->right)
            depthR = 1 + maxDepth(root->right); 

        return max(depthL, depthR);
    }
};


// DFS non-Recursive
// Time  Complexity: O(n), where n is the nodes' number in the tree
// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int depth = 0;
        stack<pair<TreeNode*, int>> s;
        s.push(make_pair(root, 1));
        while(!s.empty()) {
            TreeNode* curNode = s.top().first;
            int curDepth = s.top().second;
            s.pop();

            if (curNode->left == NULL && curNode->right == NULL)
                depth = max(depth, curDepth);
            else {
                if (curNode->left)
                    s.push(make_pair(curNode->left, curDepth+1));
                if (curNode->right)
                    s.push(make_pair(curNode->right, curDepth+1));
            }
        }
        return depth;
    }
};

int main()
{
    return 0;
}

