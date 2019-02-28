//using stack no recursion
//Time  Complexity: O(n)
//Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <stack>

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

        stack<pair<Node*, int>> s;
        s.push(make_pair(root, 1));
        int res = 1;

        while (s.empty() != true) {
            Node* w = s.top().first;
            int depth = s.top().second;
            s.pop();

            res = max(res, depth);

            for (Node* node: w->children)
                s.push(make_pair(node, depth + 1));
        }
        return res;
    }       
};


int main() {
    return 0;
}
