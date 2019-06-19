#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// The O(n^2) solution is trivial
// Two Pass
// Time  Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return ;

        //int cntZeros = 0;
        //for (int num : arr)
        //    if (num == 0) ++ cntZeros;

        int cntZeros = count(arr.begin(), arr.end(), 0);

        for (int i=n-1, j=n+cntZeros-1; i>=0 && j>=0; --i, --j) {
            if (arr[i] != 0) {
                if (j < n) arr[j] = arr[i];
            }
            else {
                if (j < n) arr[j] = arr[i];
                -- j;
                if (j <n) arr[j] = arr[i];
            }
        }
    }
};

int main()
{

    return 0;
}

