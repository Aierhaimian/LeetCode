#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> romanNum = {"M",  "CM","D", "CD","C", "XC","L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> nums        = {1000, 900, 500, 400, 100, 90,  50,  40,   10,   9,    5,   4,    1 };
        string res = "";
        for (int i=0; i<nums.size(); i++) {
            int count = num/nums[i];
            while (count != 0) {
                res+=romanNum[i];
                count --;
            }
            num = num%nums[i];
        }
        return res;
    }
};

int main()
{
    cout << Solution().intToRoman(2648) << endl;

    return 0;
}

