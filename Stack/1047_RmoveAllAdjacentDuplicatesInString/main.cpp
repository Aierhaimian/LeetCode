#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        if (S.size() == 0)
            return res;

        stack<char> stk;
        for (char c: S) {
            if (stk.empty())
                stk.push(c);
            else {
                if (stk.top() == c) {
                    stk.pop();
                    continue;
                }
                else
                    stk.push(c);
            }
        }
        if (stk.empty())
            return res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{

    return 0;
}

