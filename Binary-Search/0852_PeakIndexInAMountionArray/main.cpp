#include <iostream>
#include <vector>

using namespace std;

// Brute Force
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {

        for (size_t i=0; i<A.size()-1; i++)
        {
            if (A[i] > A[i+1])
                return i;
        }

        return -1;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

