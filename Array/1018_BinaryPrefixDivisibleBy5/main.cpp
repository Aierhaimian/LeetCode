#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Mathematics one
// Time  Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        for (int i=0; i<A.size(); i++)
        {
            int odd = 0, even = 0;
            int cntE = 0, cntO = 0;
            for (int j=i; j>=0; j--)
            {
                if ((i-j)%2 == 0)
                {
                    if (cntE%2 == 0)
                        even += A[j];
                    else
                        even -= A[j];
                    cntE ++;
                }
                else
                {
                    if (cntO%2 == 0)
                        odd += A[j];
                    else
                        odd -= A[j];
                    cntO ++;
                }
            }
            if ((2*odd + even)%5 == 0)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};

int main()
{

    return 0;
}

