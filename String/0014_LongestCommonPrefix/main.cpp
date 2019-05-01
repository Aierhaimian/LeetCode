#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Vertical Scan
// Time  Complexity: O(len(strs)*max len of string)
// Space Complexity: O(1)
class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if (strs.size() == 0) return res;

        for (int i=0; i<strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j=1; j<strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != c)
                    return res;
            }
            res += c;
        }
        return res;
    }
};

// Horizonal Scan
// Time  Complexity: O(len(strs)*max len of string)
// Space Complexity: O(1)
class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";

        string res = strs[0];
        for (int i=1; i<strs.size(); i++) {
            for (int j=0; j<res.size(); j++) {
                if (j >= strs[i].size() || strs[i][j] != res[j]){
                    res = res.substr(0, j);
                    break;
                }
            }
        }
        return res;
    }
};

// Divide and Conquer
// Time  Complexity: O(len(strs)*max len of string)
// Space Complexity: O(log(len(strs)))
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";

        return solve(strs, 0, strs.size() - 1);
    }
private:
    string solve(const vector<string> &strs, int l, int r) {
        if (l == r) return strs[l];

        int mid = (r+l)/2;

        string res1 = solve(strs, l, mid);
        string res2 = solve(strs, mid+1, r);

        int i=0;
        for (; i<res1.size() && i<res2.size(); i++) {
            if (res1[i] != res2[i])
                break;
        }

        return res1.substr(0, i);
    }
};

int main()
{

    return 0;
}

