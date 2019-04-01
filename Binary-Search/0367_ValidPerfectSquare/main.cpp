#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) return true;
        int64_t l = 0, r = num;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            int64_t sq = mid*mid;
            if (sq == num)
                return true;
            else if (sq < num)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return false;
    }
};

int main()
{

    return 0;
}

