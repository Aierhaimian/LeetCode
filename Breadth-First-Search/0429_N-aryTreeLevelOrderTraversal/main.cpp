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

        queue<pair<Node*, size_t>> q;
        q.push(make_pair(root, 0));

        while (q.empty() != true) {
            Node* w = q.front().first;
            size_t depth = q.front().second;
            q.pop();

            if (depth == res.size()) //完成一个初始化的功能
                res.push_back({w->val});
            else
                res[depth].push_back(w->val);

            for (Node* node: w->children)
                q.push(make_pair(node, depth + 1));
        }
        return res;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

