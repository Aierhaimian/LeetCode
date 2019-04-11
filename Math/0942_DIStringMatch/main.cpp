#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res;
        int l = 0, r = S.size();
        int i = 0;
        while (l <= r)
        {
            if (S[i] == 'I')
                res.push_back(l++);
            else
                res.push_back(r--);
            i++;
        }
        return res;
    }
};

int main()
{

    return 0;
}

