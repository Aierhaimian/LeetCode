#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Linear Scan
// Time  Complexity: O(n)
// Space Complextiy: O(1)
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum%3) return false;

        int cur = 0, i = 0, j = A.size() - 1;

        do{
            cur += A[i++];
        }while ((i < A.size()) && (cur != sum/3));

        if (i == A.size()) return false;

        cur = 0;
        do{
            cur += A[j--];
        }while(j >= 0 && cur! = sum/3);

        if (j < 0) return false;

        return i <= j;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

