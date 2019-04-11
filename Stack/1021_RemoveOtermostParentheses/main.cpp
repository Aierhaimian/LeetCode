#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        string tmp;
        stack<char> c_s; 
        stack<char> o_s;
        o_s.push(S[0]);

        for (size_t i=1; i<S.size(); i++)
        {
            if (S[i] == '(')
            {
                if (!o_s.empty())
                {
                    tmp.push_back(S[i]);
                    c_s.push(S[i]);
                }
                else
                    o_s.push(S[i]);
            }
            else if (S[i] == ')')
            {
                if (!c_s.empty())
                {
                    c_s.pop();
                    tmp.push_back(S[i]);
                }
                else
                {
                    res += tmp;
                    o_s.pop();
                    tmp.clear();
                }
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}

