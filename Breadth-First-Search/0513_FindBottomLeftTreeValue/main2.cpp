// DFS
// Time  Complexity: O(n)
// Space Complexity: O(n)
#include <iostream>
#include <vector>

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
        vector<int> leftNode;
        dfs(root, leftNode, 0);
        return leftNode[leftNode.size() - 1];
    }
private:
    void dfs(TreeNode* root, vector<int> &vec, size_t depth) {
        if (!root) return;

        if (vec.size() == depth) 
            vec.push_back(root->val);
        else
            vec[depth] = root->val;

        dfs(root->right, vec, depth + 1);
        dfs(root->left, vec, depth + 1);

        return;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

