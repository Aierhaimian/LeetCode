#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Greedy
// Time  Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0, ti = 0;
        while (si < s.size() && ti < t.size()) {
            if (s[si] == t[ti]) {
                si ++; 
                ti ++;
            }
            else {
                ti ++;
            }
        }
        if (si != s.size() && ti == t.size())
            return false;
        return true;
    }
};

int main()
{

    return 0;
}

