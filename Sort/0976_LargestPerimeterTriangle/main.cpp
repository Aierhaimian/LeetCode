#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

bool beq(int a, int b) {
    return a >= b;
}

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        if (A.size() < 3)
            return 0;

        sort(A.begin(), A.end(), beq);
        for (int i=0; i<A.size()-2; i++) {
            if (A[i+1] + A[i+2] > A[i])
                return A[i] + A[i+1] + A[i+2];
        }
        return 0;
    }
};

int main()
{

    return 0;
}

