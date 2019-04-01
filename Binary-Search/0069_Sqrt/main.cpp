#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        int p;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if (mid*mid <= x)
            {
                p = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return p;
    }
};

int main()
{

    return 0;
}

