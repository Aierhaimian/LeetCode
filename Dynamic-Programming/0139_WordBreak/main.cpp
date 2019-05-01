#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;



class Solution {
public:
    struct Trie {
        int ch[26];
        int cnt;
        Trie() : cnt(0) {
            memset(ch, 0, sizeof(ch));
        }
    };

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        vector<Trie> T(1);
        for (int i=0; i<n; i++) {
            int r = 0;
            for (int j=0; j<wordDict[i].size(); j++) {
                int k = wordDict[i][j] - 'a';
                if (T[r].ch[k] == 0) {
                    T.push_back(Trie());
                    T[r].ch[k] = T.size() - 1;
                }
                r = T[r].ch[k];
            }
            T[r].cnt += 1;
        }

        int m = s.size();
        vector<int> dp(m+1, 0);
        dp[m] = true;
        for (int i=m-1; i>=0; i--) {
            int r =0;
            for (int j=i; j<=m-1; j++) {
                int k = s[j] - 'a';
                if (T[r].ch[k] == 0) {
                    dp[i] = false;
                    break;
                }

                r = T[r].ch[k];
                if (T[r].cnt>0 && dp[j+1]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};

int main()
{

    return 0;
}

