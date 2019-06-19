#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// BackTrack
// Time  Complexity: O(2^n)
// Space Complexity: O(n)
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        res.clear();
        for (int i=0; i<S.size(); i++)
            if (isupper(S[i]))
                S[i] = tolower(S[i]);

        generateRes(S, 0);
        
        return res;
    }
private:
    vector<string> res;
    void generateRes(string &S, int index) {
        if (index == S.size()) {// 回溯结束条件
            res.push_back(S);
            return;
        }

        if (isalpha(S[index])) {
            generateRes(S, index + 1);
            S[index] = toupper(S[index]);
            generateRes(S, index + 1);
            S[index] = tolower(S[index]);
        }
        else {
            generateRes(S, index + 1);
        }
    }
};

int main()
{

    return 0;
}

