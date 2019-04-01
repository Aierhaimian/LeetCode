#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// TLE
class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1, r = n;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if (isOk(n, mid))
                l = mid + 1;
            else
                r = mid - 1;
        }

        return l;
    }
private:
    bool isOk(int n, int m)
    {
        int64_t sum = 0;
        while (m > 0)
        {
            sum += m;
            m--;
        }
        if (sum > n) return false;
        else return true;
    }
};

int main()
{

    return 0;
}

