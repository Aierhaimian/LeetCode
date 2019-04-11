#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res(S.size(), INT_MAX);
        vector<int> CPos;
        for (int i=0; i<S.size(); i++)
            if (S[i] == C)
                CPos.push_back(i);

        for (int i=0; i<CPos.size(); i++)
        {
            for (int j=0; j<S.size(); j++)
            {
                if (S[j] == C)
                    res[j] = 0;
                if (res[j] > abs(j-CPos[i]))
                    res[j] = abs(j-CPos[i]);
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}

