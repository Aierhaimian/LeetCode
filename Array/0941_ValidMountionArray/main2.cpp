#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        
        size_t i;
        for (i=0; i<A.size()-1; i++)
        {
            if (A[i+1] < A[i])
                break;
            else if (A[i] == A[i+1])
                return false;
        }

        if (i == 0 || (i == A.size() - 1)) return false;

        for (size_t j = i; j<A.size()-1; j++)
            if (A[j] <= A[j+1])
                return false;

        return true;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

