#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Brute Force: Generate all permutation and check validation
// Time  Complexity: O(n*2^n)
// Space Complexity: O(n)
class Solution1 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = string(n, '(') + string(n, ')');
        do {
            if (isValid(s))
                res.push_back(s);
        }while (next_permutation(s.begin(), s.end())); // 学会c++ STL 函数用法，产生全排列
        return res;
    }
private:
    bool isValid(const string &s) {
        stack<char> ss;
        for (char c: s) {
            if (c == '(') // 右括号，入栈
                ss.push(c);
            else if (ss.empty()) // 如果栈为空，则返回false
                return false;
            else // 否则，括号匹配，出栈
                ss.pop();
        }
        return true;
    }
};

// Generate valid permutation directly
// Time  Complexity: O(2^n)
// Space Complexity: O(n)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        res.clear();
        tryGenerate(n, n, "", res);
        return res;
    }
private:
    vector<string> res;
    void tryGenerate(int left, int right, const string &cur, vector<string> &res) {
        if (left == 0 && right == 0) {
            res.push_back(cur);
            return;
        }

        if (left)
            tryGenerate(left-1, right, cur+'(', res);
        if (right && left < right) // 避免先左后右
            tryGenerate(left, right-1, cur+')', res);
    }
};

int main()
{

    return 0;
}

