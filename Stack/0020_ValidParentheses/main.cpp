#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution1 {
public:
    bool isValid(string s) {
        stack<char> c_s;
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{')
                c_s.push(c);
            else {
                if (!c_s.empty()) {
                    char tmp = c_s.top();
                    c_s.pop();
                    switch(c) {
                    case ')':
                        if (tmp != '(')
                            return false;
                        break;
                    case ']':
                        if (tmp != '[')
                            return false;
                        break;
                    case '}':
                        if (tmp != '{')
                            return false;
                        break;
                    default:
                        break;
                    }
                }
                else
                    return false;
            }
        }
        if (!c_s.empty())
            return false;
        return true;
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> c_s;
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{')
                c_s.push(c);
            else {
                if (!c_s.empty()) {
                    char tmp = c_s.top();
                    c_s.pop();
                    char match;
                    switch(c) {
                    case ')':
                       match = '(';
                        break;
                    case ']':
                        match = '[';
                        break;
                    case '}':
                        match = '{';
                        break;
                    default:
                        break;
                    }
                    if (match != tmp)
                        return false;
                }
                else
                    return false;
            }
        }
        if (!c_s.empty())
            return false;
        return true;
    }
};

int main()
{
    cout << Solution().isValid("()") << endl;
    cout << Solution().isValid("()[]{}") << endl;
    cout << Solution().isValid("(]") << endl;
    cout << Solution().isValid("([)]") << endl;
    cout << Solution().isValid("{[]}") << endl;
    return 0;
}

