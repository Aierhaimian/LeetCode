#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 使用异或 A^A = 0 及 交换律：
// B^B^A = 0^A = A
// C^A^B^A^B = C^A^A^B^B = C
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};

int main()
{

    return 0;
}

