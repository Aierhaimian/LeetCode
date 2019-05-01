#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// DFS
// Time  Complexity: O((s+p)*2^(s+p))
// Space Complexity: O(s+P)
class Solution1 {
public:
    bool isMatch(string s, string p) {
        return match(s, 0, p, 0);
    }
private:
    bool match(const string &s, int sl, const string &p, int pl) {
        if (sl == s.size()) return no_more_match(p, pl);
        if (pl == p.size()) return false;

        if (pl + 1 < p.size() && p[pl+1] == '*') {
            if (s[sl] == p[pl] || p[pl] == '.')
                return match(s, sl+1, p, pl) || match(s, sl, p, pl+2);
            else
                return match(s, sl, p, pl+2);
        }
        else if (s[sl] == p[pl] || p[pl] == '.')
            return match(s, sl+1, p, pl+1);
        return false;
    }

    bool no_more_match(const string &p, int pl) {
        int i;
        for (i = pl; i<p.size(); i+=2)
            if (i+1 < p.size() && p[i+1] != '*') return false;
        return i == p.size();
    }
};

// Memory Search
// Time  Complexity: O(s*p)
// Space Complexity: O(s*p)
class Solution2 {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return match(s, 0, p, 0, dp);
    }
private:
    bool match(const string &s, int sl, const string &p, int pl,
               vector<vector<int>> &dp) {
        if (sl == s.size()) return no_more_match(p, pl);
        if (pl == p.size()) return false;

        if (dp[sl][pl] != -1)
            return dp[sl][pl];

        if (pl + 1 < p.size() && p[pl+1] == '*') {
            if (s[sl] == p[pl] || p[pl] == '.')
                return dp[sl][pl] = (match(s, sl+1, p, pl, dp) || match(s, sl, p, pl+2, dp));
            else
                return dp[sl][pl] = match(s, sl, p, pl+2, dp);
        }
        else if (s[sl] == p[pl] || p[pl] == '.')
            return dp[sl][pl] = match(s, sl+1, p, pl+1, dp);
        return dp[sl][pl] = false;
    }

    bool no_more_match(const string &p, int pl) {
        int i;
        for (i = pl; i<p.size(); i+=2)
            if (i+1 < p.size() && p[i+1] != '*') return false;
        return i == p.size();
    }
};

// Dynamic Programming
// Time  Complexity: O(s*p)
// Space Complexity: O(s*p)
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        // dp[i][j] represents if the 1st i characters in s can match the 1st j characters in p
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        // initialization:
        // 1. dp[0][0] = true, since empty string matches empty pattern
        dp[0][0] = true;

        // 2. dp[i][0] = false(which is default value of the boolean array)
        // since empty pattern cannot match non-empty string
        // 3. dp[0][j]: what pattern matches empty string ""?
        // It should be "#*#*#*#*...", or "(#*)*" if allow me to represent regex using regex :P,
        // and for this case we need to check manually

        // for dp[0][j], as we can see, the length of pattern should be even,
        // the char at the even position should be *,
        // thus for odd length, dp[0][j] = false which is default. So we can
        // just skip the odd position, i.e. j starts from 2, the interval of j is also 2.
        // and notice that the length of repeat sub-pattern #* is only 2, we
        // can just make use of dp[0][j - 2] rather than scanning j length each time
        // for checking if it matches #*#*#*#*.
        for (int j=2; j<n+1; j+=2) {
            if (p[j-1] == '*' && dp[0][j-2])
                dp[0][j] = true;
        }

        // the induction rule is very similar to edit distance, where we also consider from the end.
        // induction rule:
        // 1. if p[j] == s[i], dp[i][j] = dp[i - 1][j - 1]
        //    ######a(i)
        //    ####a(j)
        // 2. if p[j] == '.', dp[i][j] = dp[i - 1][j - 1]
        //    #######a(i)
        //    ####.(j)
        // 3. if p[j] == '*':
        //    1. if p[j-1] != '.' && p[j-1] != s[i] then b* is counted as empty. dp[i][j] = dp[i][j - 2]
        //       #####a(i)
        //       ####b*(j)
        //    2.if p[j-1] == '.' || p[j-1] == s[i]:
        //       ######a(i)
        //       ####.*(j)
        //
        //       #####a(i)
        //       ###a*(j)
        //      2.1 if p[j-1] is counted as empty, then dp[i][j] = dp[i][j - 2]
        //      2.2 if counted as one, then dp[i][j] = dp[i - 1][j - 2]
        //      2.3 if counted as multiple, then dp[i][j] = dp[i - 1][j]

        // recap:
        // dp[i][j] = dp[i - 1][j - 1]
        // dp[i][j] = dp[i - 1][j - 1]
        // dp[i][j] = dp[i][j - 2]
        // dp[i][j] = dp[i][j - 2]
        // dp[i][j] = dp[i - 1][j - 2]
        // dp[i][j] = dp[i - 1][j]
        // Observation: from above, we can see to get dp[i][j],
        // we need to know previous elements in dp, i.e. we need to compute them first.
        // which determines i goes from 1 to m - 1, j goes from 1 to n + 1

        for (int i=1; i<m+1; i++) {
            for (int j=1; j<n+1; j++) {
                char curS = s[i-1];
                char curP = p[j-1];
                if (curP == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }else if (curP == '*') {
                    char preCurP = p[j-2];
                    if (preCurP != '.' && preCurP != curS) {
                        dp[i][j] = dp[i][j-2];
                    }else {
                        dp[i][j] = (dp[i][j-2] || dp[i-1][j-2] || dp[i-1][j]);
                    }
                }else if (curS == curP) {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    cout << "1: " << Solution().isMatch("aa", "a") << endl; // false
    cout << "2: " << Solution().isMatch("aa", "a*") << endl; // true
    cout << "3: " << Solution().isMatch("ab", ".*") << endl; // true
    cout << "4: " << Solution().isMatch("aab", "c*a*b") << endl; // true
    cout << "5: " << Solution().isMatch("mississippi", "mis*is*p*") << endl; // false
    cout << "6: " << Solution().isMatch("ab", ".*c") << endl; // false
    cout << "7: " << Solution().isMatch("a", ".*..a") << endl; // false
    cout << "8: " << Solution().isMatch("", ".*") << endl; // true
    return 0;
}

