#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// C 库函数：
// char *strstr(const char *haystack, const char *needle)
// 在字符串haystack中查找第一次出现字符串needle的位置

// Brute force
// Time  Complexity: O(haystack.size() * needle.size())
// Space Complexity: O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (haystack.size() == 0) return -1;

        for (int i=0 ;i<haystack.size(); i++) {
            int sIndex = i;
            int tIndex = 0;
            while (sIndex < haystack.size()) {
                if (haystack[sIndex] == needle[tIndex]) {
                    if (tIndex == needle.size()-1)
                        return sIndex - tIndex;
                    else {
                        sIndex ++;
                        tIndex ++;
                    }
                }
                else
                    break;
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}

