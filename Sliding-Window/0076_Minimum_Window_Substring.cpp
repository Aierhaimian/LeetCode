#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution{
public:
    string minWindow(string s, string t)
    {
        // hashmap来统计t字符串中各个字符需要出现的次数
        map<char, int> HashMap;
        for (char c: t)
            HashMap[c] = HashMap.find(c) != HashMap.end() ? HashMap[c] + 1 : 1;

        // 用来计数 判断当前字符串中是否包含了t中全部字符
        int count = 0;
        // 记录当前子字符串的左右下标
        int left = 0;
        int right = 0;
        // 记录当前最小字符串的大小以及第一、最后字符的下标
        int minLen = INT_MAX;
        int minLeft = 0;
        int minRight = 0;

        for (; right < s.length(); ++right)
        {
            if (HashMap.find(s[right]) != HashMap.end()) // 向后遍历出所有包含t的字符串
            {
                if (HashMap[s[right]] > 0) count ++;

                HashMap[s[right]] -= 1; // 如果HashMap中对应的字符小于等于0就说明出现了重复
            }

            while (count == t.length()) // 得出一个符合条件的子字符串
            {
                if (right - left < minLen) // 更新min minLeft minRight
                {
                    minLen = right - left;
                    minLeft = left;
                    minRight = right;
                }

                if (HashMap.find(s[left]) != HashMap.end()) // 向左收缩 判断所删减的字符是否在map中
                {
                    if (HashMap[s[left]] >= 0) count --;
                    HashMap[s[left]] += 1;
                }
                left ++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen+1);
    }
};

int main()
{
    string s("ADDBECODEBANC");
    string t("ABC");
    cout << Solution().minWindow(s, t) << endl;
    return 0;
}

