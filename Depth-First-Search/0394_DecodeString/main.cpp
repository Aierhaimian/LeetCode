#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        string tmp = "";
        stack<int> s_n;
        stack<string> s_s;
        int cnt = 0;
        for (size_t i=0; i<s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                cnt = cnt*10 + s[i] - '0'; // cnt不一定只有一位数
            }
            else if (s[i] == '[')
            {
                s_n.push(cnt);
                s_s.push(tmp);
                cnt = 0;
                tmp.clear();
            }
            else if (s[i] == ']')
            {
                int k = s_n.top();
                s_n.pop();
                for (int j=0; j<k; j++)
                    s_s.top() += tmp;
                tmp = s_s.top();
                s_s.pop();
            }
            else
            {
                tmp += s[i];
            }
        }
        return s_s.empty() ? tmp : s_s.top();
    }
};

int main()
{

    return 0;
}

