#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// travel all the words combinations to maintain a window
// there are wl(word len) times travel
// each time, n/wl words, mostly 2 times travel for each word
// one left side of the window, the other right side of the window
// so, time complexity is O(wl * 2 * N/wl) = O(2N)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size(), cnt = words.size();
        if (n <= 0 || cnt <= 0) return ans;

        // init word occurence
        unordered_map<string, int> dict;
        for (int i=0; i<cnt; i++) dict[words[i]] ++;

        // travel all sub string combinations
        int wl = words[0].size(); // because all word are same length
        for (int i=0; i<wl; i++) {
            int left = i, count = 0;
            unordered_map<string, int> tdict;
            for (int j=i; j<=n-wl; j+=wl) { // wl times travels
                string str = s.substr(j, wl);
                // a valid word, accumulate results
                if (dict.count(str)) {
                    tdict[str] ++;
                    if (tdict[str] <= dict[str])
                        count++;
                    else {
                        // a more word, advance the window left side poossiablly
                        while (tdict[str] > dict[str]) {
                            string str1 = s.substr(left, wl);
                            tdict[str1] --;
                            if (tdict[str1] < dict[str1])
                                count --;
                            left += wl;
                        }
                    }
                    // come to a result
                    if (count == cnt) {
                        ans.push_back(left);
                        // advance one word
                        tdict[s.substr(left, wl)] --;
                        count --;
                        left += wl;
                    }
                }
                else {
                    // not a valid word, reset all vars
                    tdict.clear();
                    count = 0;
                    left = j + wl;
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}

