#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Mathematics
// Time  Complexity: O(logn)
// Space Complexity: O(1)
class Solution {
public:
    string baseNeg2(int N) {
        string res = "";
        while (N)
        {
            if (abs(N) % 2) res += "1";
            else res += "0";

            if (abs(N) % 2) N--;
            N /= -2;
        }

        reverse(res.begin(), res.end());
        return res.size() ? res : "0";
    }
};

int main()
{

    return 0;
}

