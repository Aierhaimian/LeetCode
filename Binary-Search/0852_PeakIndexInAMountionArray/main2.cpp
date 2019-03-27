#include <iostream>
#include <vector>

using namespace std;

// Binary Search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {

        int l = 0, r = A.size() - 1;
        while (l < r)
        {
            int mid = (l+r+1)/2;
            if (A[mid - 1] < A[mid])
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};


int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

