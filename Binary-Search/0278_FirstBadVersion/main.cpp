#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        int p;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if (isBadVersion(mid))
            {
                p = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return p;
    }
};

int main()
{

    return 0;
}

