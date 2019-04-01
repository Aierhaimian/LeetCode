#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return recur(1, n);
    }
private:
    int recur(int l, int r)
    {
        if (l > r) return -1;
        
        int mid = l + ((r - l) >> 1);

        if (guess(mid) == 0)
            return mid;
        else if (guess(mid) < 0)
            return recur(l, mid -1);
        else
            return recur(mid + 1, r);

    }
};

int main()
{

    return 0;
}

