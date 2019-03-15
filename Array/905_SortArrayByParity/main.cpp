#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j = A.size()-1;
        while (i < j) {
            if (A[i]%2 != 0 && A[j]%2 == 0)
                swap(A[i++], A[j--]);
            else if (A[i]%2 != 0 && A[j]%2 != 0)
                j--;
            else if (A[i]%2 == 0 && A[j]%2 == 0)
                i++;
            else {
                i++;
                j--;
            }
        }
        return A;
    }
};

int main()
{
    vector<int> vec = {3,1,2,4};
    vector<int> res = Solution().sortArrayByParity(vec);
    for(int i: res)
        cout << i << " ";
    cout << endl;

    return 0;
}

