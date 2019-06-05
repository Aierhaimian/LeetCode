#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string res, tmp;
        stringstream ss(path);

        while (getline(ss, tmp, '/')) {
            if (tmp != "" && tmp != "." && tmp != "..")
                s.push(tmp);
            else if (tmp == ".." && !s.empty())
                s.pop();
        }

        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }

        return res.empty() ? "/" : res;
    }
};

int main()
{

    return 0;
}

