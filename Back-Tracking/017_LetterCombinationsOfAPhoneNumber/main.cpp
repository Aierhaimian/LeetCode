// Time  Complexity: O(2^n)
// Space Complexity: O(n)
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        res.clear();

        if(digits == "")
            return res;

        findCombination(digits, 0, ""); // 初始s为空

        return res;
    }
private:
    vector<string> res;
    
    const string letterMap[10] = {
        " ",    // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };
    // s中保存了此时从digits[0...index-1]翻译得到的一个字母字符串
    // 寻找和digits[index]匹配的字母，获得digits[0...index]翻译得到的解
    void findCombination(const string &digits, size_t index, const string &s)
    {

        cout << index << ": " << s << endl;

        if(index == digits.size()) {
            // 保存s，表示一种可能的组合
            res.push_back(s);
            cout << "get " << s << " , return" << endl;
            return;
        }
        char c = digits[index]; // 数字字符串中index对应的数字
        assert(c >= '0' && c <= '9' && c != '1');
        string letters = letterMap[c - '0']; // 该数字对应哪些字母
        for(size_t i=0; i<letters.size(); i++) { // 遍历letters
            cout << "digits[" << index << "] = " << c <<", use " << letters[i] << endl;
            findCombination(digits, index+1, s + letters[i]); // 处理数字字符串中下一个数字
        }
        cout << "digits[" << index << "] = " << c << " complete, return. " << endl;
        return;
    }
};

int main()
{
    vector<string> res = Solution().letterCombinations("234");
    for(auto s: res)
        cout << s << endl;
    return 0;
}

