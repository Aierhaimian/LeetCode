#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;

        for (int i=0; i<ops.size(); i++)
        {
            if (ops[i] == "C")
                s.pop();
            else if (ops[i] == "D")
            {
                int tmp = s.top();
                s.push(tmp*2);
            }
            else if (ops[i] == "+")
            {
                int tmp1 = s.top();
                s.pop();
                int tmp2 = s.top();
                s.push(tmp1);
                s.push(tmp1 + tmp2);
            }
            else
                s.push(stoi(ops[i]));
        }
        int res = 0;
        while (!s.empty())
        {
            int tmp = s.top();
            res += tmp;
            s.pop();
        }
        return res;
    }
};

int main()
{

    return 0;
}

