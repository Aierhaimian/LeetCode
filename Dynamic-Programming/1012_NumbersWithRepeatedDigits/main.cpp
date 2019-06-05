#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Combination Mathematics
// Time  Complexity: O(log(N)^2)
// Space Complexity: O(logN)
class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        vector<int> diff(10, 0);
        for (int i = 1; i <= 9; i++)
            diff[i] = get_diff(i);
        for (int i=1; i<10; i++)
            diff[i] += diff[i-1];
        for (int e: diff)
            cout << e << " ";
        cout << endl;

        vector<int> power10(10, 1);
        for (int i=1; i < 10; i++)
            power10[i] = power10[i-1]*10;
        for (int e: power10)
            cout << e << " ";
        cout << endl;

        vector<int> num;
        while(N) {
            num.push_back(N%10);
            N /= 10;
        }
        reverse(num.begin(), num.end());
        for (int e: num)
            cout << e << " ";
        cout << endl;

        int res = power10[num.size()-1] - 1 - diff[num.size() - 1];
        cout << res << endl;

        unordered_set<int> digits;
        for (int i=0; i<num.size(); i++) {
            if (i == num.size()-1) {
                for (int d=0; d<=num[i]; d++)
                    if (digits.count(d)) res ++;
                break;
            }
            else if (num[i]) {
                int tres = (num[i] - (i == 0)) * power10[num.size() - 1 - i];
                if (tres) {
                    tres -= howmanydiff(num.size() - i, digits, num[i], i != 0);
                    res += tres;
                }
            }

            if (!digits.count(num[i]))
                digits.insert(num[i]);
            else {
                res += 1 + get_num(num, i + 1);
                break;
            }
        }
        return res;
    }
private:
    int get_diff(int n) {
        int res = 9;
        n --;

        int cur = 9;
        while(n --)
            res *= cur --;
        return res;
    }

    int get_num(const vector<int> &num, int s) {
        int res = 0;
        for (int i=s; i<num.size(); i++)
            res = res*10 + num[i];
        return res;
    }

    int howmanydiff(int n, const unordered_set<int> &digits, int first, bool canZero) {
        int res = 0;
        for (int i=canZero ? 0 : 1; i<first; i++)
            if (!digits.count(i))
                res ++;
        n --;

        int cur = 10 - (digits.size() + 1);
        while (n --)
            res *= cur --;
        return res;
    }
};

https://leetcode.com/problems/numbers-with-repeated-digits/discuss/258212/Share-my-O(logN)-C%2B%2B-DP-solution-with-proof-and-explanation

class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        if(N < 10) return 0;
        int k = 0;
        for(int i = N; i > 0; i /= 10) k++;
        int digit[k] = {0};
        for(int i = 0, j = N; i < k; i++, j /= 10) digit[k - 1 - i] = j % 10;

        int noDupBaseSum = 0;
        int noDupBase[k - 1] = {0};
        for(int i = 0; i < k - 1; i++)
        {
            noDupBase[i] = i == 0 ? 9 : noDupBase[i - 1] * (10 - i);
            noDupBaseSum += noDupBase[i];
        }

        int count[10] = {0};
        int noDupRes[k] = {0};
        bool duplicate = false;
        for(int i = 0; i < k; i++)
        {
            noDupRes[i] = i == 0 ? 9 : noDupRes[i - 1] * (10 - i);
            if(!duplicate)
            {
                int diff = 0;
                for(int j = digit[i] + 1; j < 10; j++) diff += count[j] == 0;
                noDupRes[i] -= diff;
                count[digit[i]]++;
                if(count[digit[i]] > 1) duplicate = true;
            }
        }
        return N - (noDupBaseSum + noDupRes[k - 1]);
    }
};

int main()
{

    return 0;
}

