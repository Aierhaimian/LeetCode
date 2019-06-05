#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Simulation
// Time  Complexity: O(logN)
// Space Complexity: O(logN)
class Solution {
public:
    int bitwiseComplement(int N) {
        // corner case
        if (N == 0) return 1;

        vector<int> binary;
        while(N) { // 十进制转二进制：除2取余法。减一求补
            binary.push_back(1 - N%2);
            N /= 2;
        }
        reverse(binary.begin(), binary.end());

        int res = 0;
        for (int b: binary) {
            res = res*2 + b; // 二进制转十进制
        }
        return res;
    }
};

int main()
{

    return 0;
}

