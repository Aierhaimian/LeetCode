//BFS
//Time  Complexity: O(n)
//Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root)
            return 0;

        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 1));
        int res = 1;

        while (q.empty() != true) {
            Node* w = q.front().first;
            int depth = q.front().second;
            q.pop();

            res = max(res, depth);

            for (Node* node: w->children)
                q.push(make_pair(node, depth + 1));
        }
        return res;
    }
};


int main() {
    return 0;
}
