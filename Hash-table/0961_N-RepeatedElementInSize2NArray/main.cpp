#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution1 {
public:
    int repeatedNTimes(vector<int>& A) {
        sort(A.begin(), A.end());
        for (int i=1; i<A.size(); ++i)
        {
            if (A[i-1] == A[i])
                return A[i];
        }
        return -1;
    }
};

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int N = A.size()/2;
        int maxA = INT_MIN;
        int p[10000] = {0};
        for (int i=0; i<A.size(); ++i)
        {
            if (maxA < A[i]) maxA = A[i];
            p[A[i]] += 1;
            cout << A[i] << " " << p[A[i]] << endl;
        }

        for (int i=0; i<=maxA; ++i)
        {
            cout << i << " " << A[i] << endl;
            if (p[i] == N)
                return i;
        }
        return -1;
    }
};

int main()
{
    vector<int> vec = {1,2,3,3};
    int res = Solution().repeatedNTimes(vec);
    cout << res << endl;
    return 0;
}

