#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool isInc = isMonotoneInc(A);
        bool isDec = isMonotoneDec(A);
        return (isInc || isDec);

    }
private:
    bool isMonotoneInc(vector<int>& A)
    {
        for (size_t i = 0; i<A.size()-1; i++)
        {
            if (A[i] > A[i+1])
                return false;
        }
        return true;
    }

    bool isMonotoneDec(vector<int>& A)
    {
        for (size_t i=0; i<A.size()-1; i++)
        {
            if (A[i] < A[i+1])
                return false;
        }
        return true;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

