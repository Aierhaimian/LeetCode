#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// Recursive
// Time  Complexity: O(n)
// Space Complexity: O(h)
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (!root) return res;

        dfs(root, res);

        return res;
    }
private:
    void dfs (Node *r, vector<int> &vec)
    {
        if (!r) return;

        vec.push_back(r->val);

        for (auto next: r->children)
            dfs(next, vec);
    }
};

int main()
{

    return 0;
}

