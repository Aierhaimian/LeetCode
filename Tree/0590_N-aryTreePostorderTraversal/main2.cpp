#include <iostream>
#include <vector>
#include <stack>
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

// Iteratively
// Using stack
// Time  Complexity: O(n)
// Space Complexity: O(h)
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (!root) return res;

        stack<Node *> s;
        s.push(root);

        while (!s.empty())
        {
            Node *cur = s.top();
            res.push_back(cur->val);
            s.pop();

            for (auto next: cur->children)
                s.push(next);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{

    return 0;
}

