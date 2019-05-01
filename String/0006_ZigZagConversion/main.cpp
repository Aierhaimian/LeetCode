#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 题目要求将给定的字符串s摆成有numRows行的“之”字形
// 比如给定字符创”0123456789ABCDEF“
//
// numRows = 1
// 0123456789ABCDEF
//
// numRows = 2
// 02468ACE
// 13579BDF
//
// numRows = 3
// 0 4 8 C
// 13579BDF
// 2 6 A E
//
// numRows = 4
//
//  j 0123456
// i----------
// 0| 0  6  C
// 1| 1 57 BD
// 2| 24 8A E
// 3| 3  9  F

// 通过自己举的例子，可以发现以下规律：
// 黑色：第0,numRows-1,...,j+numRows-1列元素，相邻两列之间元素index差值为2*numRows-2
// 红色：其余列元素出现的位置为j+(2*numRows-2)-2*i
// 其中j为前一个黑色的列数，i为当前行数
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (n == 0 || numRows <= 1) return s;

        string res = "";
        int interval = 2*numRows - 2;
        for (int i=0; i<numRows; i++) {
            for (int j=i; j<n; j+=interval) {
                res += s[j];
                int tmp = j + interval - 2 * i;
                if (i != 0 && i != numRows-1 && tmp < n)
                    res += s[tmp];
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}

