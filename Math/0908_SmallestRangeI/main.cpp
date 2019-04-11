#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

// 比较最大值与最小值的差值与2*K之间的关系
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        if (A.back() - A.front() <= 2*K) return 0;
        else
            return A.back() - A.front() - 2*K;
    }
};

int main()
{

    return 0;
}

