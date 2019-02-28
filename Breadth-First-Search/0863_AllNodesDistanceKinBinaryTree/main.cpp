#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Construct a Graph and Using BFS
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (K == 0)
            return {target->val};

        vector<vector<int>> g;
        vector<int> value;

        int targetIndex = -1;
        constructGraph(g, value, root, -1, target, targetIndex);
        assert(targetIndex >= 0);

        int n = value.size();
        assert(n == g.size());

        vector<int> res;
        vector<bool> visited(n, false);

        queue<pair<int, int>> q;
        q.push(make_pair(targetIndex, 0));
        visited[targetIndex] = true;

        while (!q.empty()) {
            int curIndex = q.front().first;
            int curDis = q.front().second;
            q.pop();

            if (curDis == K)
                res.push_back(value[curIndex]);

            for (int nextIndex: g[curIndex])
                if (!visited[nextIndex]) {
                    q.push(make_pair(nextIndex, curDis + 1));
                    visited[nextIndex] = true;
                }
        }
        return res;
    }

private:
    void constructGraph(vector<vector<int>> &g, vector<int> &value, TreeNode *root, int parent, TreeNode *target, int &targetIndex) {
        value.push_back(root->val);
        g.push_back(vector<int>());
        int index = value.size() - 1;

        if (parent != -1)
            g[index].push_back(parent);

        if (root->left != NULL) {
            g[index].push_back(value.size());
            constructGraph(g, value, root->left, index, target, targetIndex);
        }

        if (root->right != NULL) {
            g[index].push_back(value.size());
            constructGraph(g, value, root->right, index, target, targetIndex);
        }

        if (root == target)
            targetIndex = index;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

