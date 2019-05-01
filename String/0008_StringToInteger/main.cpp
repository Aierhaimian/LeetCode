#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        if (n == 0) return 0;

        int sflag = 0; // 数字正负号标志
        bool nflag = false; // 数字开始标志
        vector<int> num; // 存储数字
        for (int i=0; i<n; i++) {
            if (str[i] == ' ' && nflag == false) { // 消灭空格，但正负号后不能再有空格
                if (sflag != 0)
                    return 0;
                continue;
            }
            else if (str[i] == '+' && nflag == false) { // 判断'+'号，保证符号唯一性
                if (sflag == 0)
                    sflag = 1;
                else
                    return 0;
            }
            else if (str[i] == '-' && nflag == false) { // 判断'-'号，保证符号唯一性
                if (sflag == 0)
                    sflag = -1;
                else
                    return 0;
            }
            else if (str[i] >= '0' && str[i] <= '9') { // 存储数字
                nflag = true;
                num.push_back(str[i] - '0');
            }
            else {
                return 0; // 其他情况均为错误，返回0
            }
        }

        if (nflag == false) return 0; // 无数字，返回0
        if (nflag == true && sflag == 0) sflag = 1; // 无正负号，默认数字为正数

        int res = 0; // 最终结果
        for (int i: num) {
            if (sflag == 1 && (res > INT_MAX/10 || (res == INT_MAX/10 && i >= 7))) // 正数溢出判断
                return INT_MAX;
            if (sflag == -1 && (res > INT_MAX/10 || (res == INT_MAX/10 && i >= 8))) // 负数溢出判断
                return INT_MIN;

            res = res*10 + i;
        }
        return sflag == 1 ? res : -res;
    }
};

int main()
{

    string str1 = "42";
    cout << Solution().myAtoi(str1) << endl;
    string str2 = "   -42";
    cout << Solution().myAtoi(str2) << endl;
    string str3 = "4193 with words";
    cout << Solution().myAtoi(str3) << endl;
    string str4 = "word 4193 with words";
    cout << Solution().myAtoi(str4) << endl;
    string str5 = "2147483646";
    cout << Solution().myAtoi(str5) << endl;
    string str6 = "2147483647";
    cout << Solution().myAtoi(str6) << endl;
    string str7 = "2147483648";
    cout << Solution().myAtoi(str7) << endl;
    string str8 = "-2147483647";
    cout << Solution().myAtoi(str8) << endl;
    string str9 = "-2147483648";
    cout << Solution().myAtoi(str9) << endl;
    string str10 = "-2147483649";
    cout << Solution().myAtoi(str10) << endl;
    string str11 = "0";
    cout << Solution().myAtoi(str11) << endl;
    string str12 = "-1";
    cout << Solution().myAtoi(str12) << endl;
    string str13 = "2343289478927589437589435748975943";
    cout << Solution().myAtoi(str13) << endl;
    string str14 = "   21474sdfdf83646";
    cout << Solution().myAtoi(str14) << endl;
    string str15 = "   -2147483  64wedfsf6";
    cout << Solution().myAtoi(str15) << endl;
    string str16 = "-91283472332";
    cout << Solution().myAtoi(str16) << endl;
    string str17 = "91283472332";
    cout << Solution().myAtoi(str17) << endl;
    string str18 = "+-2";
    cout << Solution().myAtoi(str18) << endl;
    string str19 = "- 123";
    cout << Solution().myAtoi(str19) << endl;
    return 0;
}

