#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> B;
        while(K)
        {
            B.push_back(K%10);
            K /= 10;
        }
        reverse(B.begin(), B.end());

        int m = A.size() - 1;
        int n = B.size() - 1;

        vector<int> res;
        int c = 0;
        while (m >=0 && n >= 0)
        {
            int tmp = A[m--] + B[n--] + c;
            if (tmp > 9)
            {
                tmp %= 10;
                c = 1;
            }
            else
                c = 0;

            res.push_back(tmp);
        }

        int c1 = 0;
        while (m >= 0)
        {
            int tmp = A[m--] + c1 + c;
            c = 0;
            if (tmp > 9)
            {
                tmp %= 10;
                c1 = 1;
            }
            else
                c1 = 0;
            res.push_back(tmp);
        }
        if (c1 == 1) res.push_back(1);

        int c2 = 0;
        while (n >= 0)
        {
            int tmp = B[n--] + c2 + c;
            c = 0;
            if (tmp > 9)
            {
                tmp %= 10;
                c2 = 1;
            }
            else
                c2 = 0;
            res.push_back(tmp);
        }
        if (c2 == 1) res.push_back(1);

        if (c == 1) res.push_back(1);

        reverse(res.begin(), res.end());

        return res;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

