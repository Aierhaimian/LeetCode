#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        if (n == 0) return 0;

        string tmp;
        for (int i=0; i<n; i++) {
            if (s[i] == ' ' && i+1 != n && s[i+1] != ' ')
                tmp.clear();
            else if (s[i] == ' ' && i+1 != n && s[i+1] == ' ')
                continue;
            else if (s[i] == ' ' && i+1 == n)
                break;
            else {
                tmp.push_back(s[i]);
            }
        }

        return tmp.size();
    }
};

int main()
{
    string str1 = "a";
    cout << Solution().lengthOfLastWord(str1) << endl;

    string str2 = "        a";
    cout << Solution().lengthOfLastWord(str2) << endl;

string str3 = "a           ";
    cout << Solution().lengthOfLastWord(str3) << endl;

string str4 = "     a      ";
    cout << Solution().lengthOfLastWord(str4) << endl;


    return 0;
}

