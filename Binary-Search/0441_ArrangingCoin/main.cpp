#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int i;
        for (i=1; i<=n; i++)
        {
            if (n > 0)
                n -= i;
            else
                break;
        }
        return i-1;
    }
};

int main()
{

    return 0;
}

