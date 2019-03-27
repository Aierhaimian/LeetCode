#include <iostream>
#include <vector>

using namespace std;

// move the largest element to the end of array
// Time  Complexity: O()
// Space Complexity: O()
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        if (A.size() == 0) return res;
        if (A.size() == 1)
        {
            res.push_back(0);
            return res;
        }

        for (int i=A.size()-1; i>0; i--)
        {
            int maxA = INT_MIN;
            int locA = -1;
            for (int j=i; j>=0; j--)
            {
                if (A[j] > maxA)
                {
                    maxA = A[j];
                    locA = j;
                }
            }

            if (locA == i) continue;

            res.push_back(locA + 1);
            res.push_back( i + 1);
            reverse(A.begin(), A.begin() + locA + 1);
            reverse(A.begin(), A.begin() + i + 1);
        }
        return res;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

