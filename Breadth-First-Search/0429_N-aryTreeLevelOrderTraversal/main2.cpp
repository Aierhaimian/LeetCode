//BFS, using queue
//No need to store depth in the queue
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<Node*> q;
        q.push(root);

        while (q.empty() != true) {
            int n = q.size();
            vector<int> level;
            for (int i=0; i<n; i++) {
                Node* w = q.front();
                q.pop();
                level.push_back(w->val);
                for (Node* node: w->children)
                    q.push(node);
            }
            res.push_back(level);
        }
        return res;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

