#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// C 库函数：
// char *strstr(const char *haystack, const char *needle)
// 在字符串haystack中查找第一次出现字符串needle的位置
// 我们记：haystack为主串其长度为n；needle为模式串，其长度为m
// n > m
//
// BF: Brute Force
// 我们在主串中，检查起始位置分别是0,1,2,...,n-m且长度为n-m+1个子串
// 是否有跟模式串匹配
// Time  Complexity: O(n * m)
// Space Complexity: O(1)
//
// 优化前：
// Run Time：1432ms
// Memory Usage：9.1MB
class Solution1 {
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

// 优化后
// Run Time: 4ms
// Memory Usage: 9.1MB
class Solution2 {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0) return 0;
        if (n == 0) return -1;

        for (int i=0; i<n-m+1; i++) {
            int sIndex = i;
            int tIndex = 0;
            while (sIndex < n) {
                if (haystack[sIndex] == needle[tIndex]) {
                    if (tIndex == m-1)
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

// RK: Rabin-Karp
// 我们通过哈希算法对主串中的n-m+1个子串分别求哈希值
// 然后逐个与模式串的哈希值比较大小：
// 如果某个子串的哈希值与模式串相等，那就说明对应的子串和模式串匹配

// 此哈希算法优点是不会有冲突，但是模式串太长就会溢出的
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution3 {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if (haystack == "") return -1;

        int n = haystack.size();
        int m = needle.size();
        if (n < m) return -1;

        vector<long long> record;
        for (int i=m-1; i>=0; i--)
            record.push_back(pow(26, i));

        long long patternHash = 0;
        vector<long long> subHash(n-m+1, 0);
        for (int i=0; i<m; i++) {
            patternHash += (needle[i] - 'a')*record[i];
            subHash[0] += (haystack[i] - 'a')*record[i];
        }

        if (patternHash == subHash[0]) return 0;

        for (int i=1; i<n-m+1; i++) {
            subHash[i] = 26*(subHash[i-1] - record[0]*(haystack[i-1]-'a')) + (haystack[i+m-1] - 'a');
            if (subHash[i] == patternHash)
                return i;
        }
        return -1;
    }
};

// Rabin-Karp
// 此算法中哈希函数设计会有冲突，因此需要解决哈希冲突
// 极端情况下此算法时间复杂度会回退到BF算法的时间复杂度
// Time  Complexity: O(n * m)
// Sapce Complexity: O(m)
class Solution4 {

private:
    const int MOD = 1e9 + 7;
    const int base = 256;

public:
    int strStr(string haystack, string needle) {

        if(needle == "") return 0;
        if(haystack == "") return -1;

        int n = haystack.size(), m = needle.size();
        if(n < m) return -1;

        int h = 1, txthash = 0, patternhash = 0;
        for(int i = 0; i < m - 1; i ++){
            h = h * 256ll % MOD;
            txthash = (txthash * 256ll + haystack[i]) % MOD;
            patternhash = (patternhash * 256ll + needle[i]) % MOD;
        }
        patternhash = (patternhash * 256ll + needle[m - 1]) % MOD;

        for(int i = m - 1; i < n; i ++){
            txthash = (txthash * 256ll + haystack[i]) % MOD;
            if(txthash == patternhash && same(haystack, i - m + 1, i, needle))
                return i - m + 1;

            txthash -= haystack[i - m + 1] * (long long)h % MOD;
            if(txthash < 0) txthash += MOD;
        }
        return -1;
    }

private:
    bool same(const string& s, int start, int end, const string& t){
//        assert(end - start + 1 == t.size());
        for(int i = start; i <= end; i ++)
            if(s[i] != t[i - start])
                return false;
        return true;
    }
};


// BM: Boyer-Moore
// 坏字符规则 + 好后缀规则
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution5 {
public:
    int strStr(string haystack, string needle) {
        // corner case
        if (needle == "") return 0;
        if (haystack == "") return -1;

        int n = haystack.size();
        int m = needle.size();

        // 坏字符规则
        vector<int> bad(256, -1); // 记录模式串中每个字符最后出现的位置
        generateBad(needle, bad);

        // 好后缀规则
        vector<int>suffix(m, -1);
        vector<bool> prefix(m, false);
        generateGood(needle, suffix, prefix);

        int i = 0; // i表示主串与模式串对齐的第一个字符
        while (i <= n-m) {
            int j;
            for (j=m-1; j>=0; j--) { // 模式串从后往前匹配
                if (haystack[i+j] != needle[j]) // 坏字符对应模式串中的下标是j
                    break;
            }
            if (j<0)
                return i; // 匹配成功，返回主串与模式串第一个匹配的字符的位置
            // 这里等同于将模式串往后滑动 j-bad[haystack[i+j]]位
            int x = j - bad[haystack[i+j]]; // si - xi
            int y = 0;
            if (j < m-1) { // 如果有好后缀
                y = moveByGS(j, m, suffix, prefix); // 由好后缀规则，移动j-suffix[k]+1位，r位或者m位
            }
            i = i + max(x, y); // 在坏字符规则和好后缀规则中选择一个最大的
        }
        return -1;
    }
private:
    void generateBad(const string &needle, vector<int> &bad) {
        int m = needle.size();
        for (int i=0; i<m; i++)
            bad[needle[i]] = i; // 构建坏字符哈希表
    }

    void generateGood(const string &needle, vector<int> &suffix, vector<bool> &prefix) {
        int m = needle.size();
        for (int i=0; i<m-1; i++) { // needle[0, i]
            int j = i;
            int k = 0; // 公共后缀子串长度
            while (j>=0 && needle[j] == needle[m-1-k]) { // 与needle[0,m-1]求公共后缀子串
                --j;
                ++k;
                suffix[k] = j+1; // j+1 表示公共后缀子串在needle[0,i]中的起始下标
            }
            if (j == -1)
                prefix[k] = true; // 如果公共后缀子串也是模式串的前缀子串
        }
    }

    int moveByGS(int j, int m, const vector<int> &suffix, const vector<bool> &prefix) {
        int k = m-1-j; // 好后缀长度
        if (suffix[k] != -1)
            return j - suffix[k] + 1;
        for (int r = j+2; r <= m-1; r++) { // j是坏字符的下标，好后缀的下标是j+1
            if (prefix[m-r] == true)
                return r;
        }
        return m;
    }

};

int main()
{
    string str1 = "abbbbbaa";
    string str2 = "abbb";
    cout << Solution().strStr(str1, str2) << endl;

    string str3 = "hello";
    string str4 = "ll";
    cout << Solution().strStr(str3, str4) << endl;

    string str5 = "sdfhuhvbvjkef";
    string str6 = "kef";
    cout << Solution().strStr(str5, str6) << endl;

    return 0;
}

