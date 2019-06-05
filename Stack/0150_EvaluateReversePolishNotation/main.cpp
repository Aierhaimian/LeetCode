#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution1 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        int a, b;
        for (string str: tokens) {
            if (str[0] >= '0' && str[0] <= '9' || str[0] == '-' && str[1] != '\0') {
                numbers.push(stoi(str));
            }
            else {
                switch(str[0]) {
                case '+':
                    a = numbers.top();
                    numbers.pop();
                    b = numbers.top();
                    numbers.pop();
                    numbers.push(b + a);
                    break;
                case '-':
                    a = numbers.top();
                    numbers.pop();
                    b = numbers.top();
                    numbers.pop();
                    numbers.push(b - a);
                    break;
                case '*':
                    a = numbers.top();
                    numbers.pop();
                    b = numbers.top();
                    numbers.pop();
                    numbers.push(b * a);
                    break;
                case '/':
                    a = numbers.top();
                    numbers.pop();
                    b = numbers.top();
                    numbers.pop();
                    numbers.push(b / a);
                    break;
                default:
                    break;
                }
            }
        }
        int res = numbers.top();
        numbers.pop();
        return res;
    }
};

class Solution {
public:
    //此算法思想较为简单，即遇到数字将数字入栈，直到遇到一个运算符，此时出栈两个数字做运算，将
    //运算结果再次入栈，继续遍历数组直到结束。
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (auto s: tokens)
        {
            if (s.size() > 1 || isdigit(s[0])) //原型：int isdigit(char c); 判断字符c是否为数字，当c为数字0-9时，返回非零值，否则返回零。
                stk.push(stoi(s));
            else{
                auto x2 = stk.top();
                stk.pop();
                auto x1 = stk.top();
                stk.pop();

                switch (s[0])
                {
                    case '+':
                        x1 += x2;
                        break;
                    case '-':
                        x1 -= x2;
                        break;
                    case '*':
                        x1 *= x2;
                        break;
                    case '/':
                        x1 /= x2;
                        break;

                    default:
                        break;
                }
                stk.push(x1);
            }
        }

        return stk.top();
    }
};

int main()
{

    return 0;
}

