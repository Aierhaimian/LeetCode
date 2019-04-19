#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 用回溯方法会TLE，因此需要寻找规律：
// 假设有四位数字{1,2,3,4}，那么它们可以产生的所有排列按
// 下面的式子递归产生
// 1 + {2,3,4}
// 2 + {1,3,4}
// 3 + {1,2,4}
// 4 + {1,2,3}
// 当选定一个数字后，其他剩下的数字进行组合排列，就可以
// 求出以该数字打头的所有排列组合。
// 那么我们要求第14个组合数，由于14 = 6 + 6 + 2
// 我们只需在3打头的排列数中求出第二个排列数
// 那么就完成了本题。
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> permutation(n+1, 1);
        // 求出1到n每个数字各有几种全排列
        for (int i=1; i<=n; i++)
            permutation[i] = permutation[i-1]*i;

        vector<char> digits = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int num = n-1;
        string res;
        while (num) {
            int t = (k-1) / (permutation[num--]); // 求当前打头数字，更新num
            k = k-t*permutation[num+1]; // 更新k
            res.push_back(digits[t]);
            digits.erase(digits.begin()+t);
        }
        res.push_back(digits[k-1]);
        return res;
    }
};

int main()
{

    return 0;
}

