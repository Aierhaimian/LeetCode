//DFS
//Time  Complexity: O(n)
//Space Complexity: O(n)

#include <iostream>
#include <vector>

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

        int depth = 1;

        for (Node* child: root->children) {
            depth = max(depth, 1 + maxDepth(child));
        }

        return depth;
    }
};


int main() {
    return 0;
}
