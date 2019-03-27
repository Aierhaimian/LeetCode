#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int trend = 0;
        for (size_t i = 1; i < A.size(); i++)
        {
            if (trend == 0)
            {
                if (A[i] > A[i-1]) trend = 1;
                else if (A[i] < A[i-1]) trend = -1;
            }
            else
            {
                if ((A[i] > A[i-1]) && trend == -1) return false;
                else if ((A[i] < A[i-1]) && trend == 1) return false;
            }
        }

        return true;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

