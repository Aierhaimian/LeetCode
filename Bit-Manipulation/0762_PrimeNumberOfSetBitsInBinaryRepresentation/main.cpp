#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

https://blog.csdn.net/m0_37586991/article/details/79673837

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i=L; i<=R; i++) {
            vector<int> binary;
            int n = i;
            while(n) {
                binary.push_back(n%2);
                n /= 2;
            }

            int oneCnt = 0;
            for (int i: binary)
                if (i == 1)
                    oneCnt ++;

            if (oneCnt != 1 && isPrime(oneCnt))
                res ++;
        }
        return res;
    }
private:
    bool isPrime(int n) {
        if (n == 2 || n == 3)
            return true;
        if (n % 6 != 1 && n % 6 != 5) // 不在6的倍数的两侧的一定不是质数
            return false;
        int tmp = int(sqrt(n));
        for (int i=5; i<tmp+1; i+=6) {
            if (n % i ==0 || n % (i+2) == 0)
                return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}

