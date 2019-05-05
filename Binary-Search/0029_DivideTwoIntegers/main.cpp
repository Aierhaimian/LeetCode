#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 15 = 3*2^2 + 3*2^0
// 15/3 = 2^2 + 2^0 = 5
class Solution {
public:
    int divide(int dividend, int divisor) {
        // corner case
        if (dividend == divisor) return 1;
        if (divisor == 1) return dividend;
        if (dividend == 0 || divisor == INT_MIN) return 0;
        // This situation will be overflow
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // get sign
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;

        // convert both to negtive
        int a = dividend;
        int b = divisor;
        if (a > 0) a = -a;
        if (b > 0) b = -b;
        if (b < a) return 0;

        int res = 0;
        int sub = b;
        int cnt = 1;
        while (true) {
            while ((sub >= (INT_MIN >> 1)) && (a - (sub +sub) < 0)) {
                sub += sub;
                cnt += cnt;
            }
            a -= sub;
            res += cnt;
            // re-init
            sub = b;
            cnt = 1;
            if (a > b)
                break;
        }
        return sign > 0 ? res : -res;
    }
};

int main()
{

    return 0;
}

