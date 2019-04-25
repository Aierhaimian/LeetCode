#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int maxLen = 1;
        vector<vector<bool>> memo(n, vector<bool>(n, false));
        string longestSub;
        for (int l=0; l<n; l++) {
            for (int i=0; i<n-l; i++) {
                int j = i+l;
                if (s[i] == s[j] && (j-i<=2 || memo[i+1][j-1])) {
                    memo[i][j] = true;

                    if (j-i+1 > maxLen) {
                        maxLen = j-i+1;
                        longestSub = s.substr(i, maxLen);
                    }
                }
            }
        }
        if (maxLen == 1) return longestSub = s.substr(0, 1);
        return longestSub;
    }
};

int main()
{

    return 0;
}

