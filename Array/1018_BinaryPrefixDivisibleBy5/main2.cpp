#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Mathematics
// Time  Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int> &A)
    {
        int n = A.size();
        vector<bool> res;

        int a = 0;
        for (int i: A)
        {
            a = a * 2 + i;
            res.push_back(a%5 == 0);
            a %= 10;
        }
        return res;
    }
};

int main()
{

    return 0;
}

