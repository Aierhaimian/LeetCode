#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        long long l = 0, r = (1LL << 32), mid, p;
        while (l <= r)
        {
            mid = l + ((r - l) >> 1);
            if (isOk(houses, heaters, mid))
            {
                p = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return p;
    }
private:
    bool isOk(vector<int> &houses, vector<int> &heaters, long long radius)
    {
        long long L, R;
        size_t i, j;
        for (i=j=0; i<heaters.size(); ++i)
        {
            L = heaters[i] - radius;
            R = heaters[i] + radius;
            for (; j<houses.size() && L<=houses[j] && houses[j]<=R; ++j)
                ;
        }

        return i==heaters.size() && j==houses.size();
    }
};

int main()
{

    return 0;
}

