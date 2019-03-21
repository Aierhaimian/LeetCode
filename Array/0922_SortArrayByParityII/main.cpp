#include <iostream>
#include <vector>

using namespace std;

// Seperate odd and even elements into different vectors
// Time  Complexity: O(n)
// Space Complexity: O(2*n)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> odd, even;
        for (int a: A) {
            if (a%2 == 0)
                even.push_back(a);
            else
                odd.push_back(a);
        }

        vector<int> res;
        int p_odd = 0;
        int p_even = 0;
        for (size_t i=0; i<A.size(); i++) {
            if (i%2 != 0)
                res.push_back(odd[p_odd++]);
            else
                res.push_back(even[p_even++]);
        }

        return res;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

