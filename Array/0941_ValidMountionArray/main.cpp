#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        int maxNum = INT_MIN;
        size_t sumit = -1;
        for (size_t i=0; i<A.size(); i++)
        {
            if (A[i] > maxNum)
            {
                maxNum = A[i];
                sumit = i;
            }
        }

        if (sumit == 0 || (sumit == A.size() - 1)) return false;

        for (size_t i = 0; i < sumit; i++)
            if (A[i] >= A[i+1]) return false;

        for (size_t i = sumit; i < A.size()-1; i++)
            if (A[i] <= A[i+1]) return false;

        return true;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

