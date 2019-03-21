#include <iostream>
#include <vector>

using namespace std;

// Burte Froce
// Time  Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size();
        assert(m >= 0);
        int n = A[0].size();
        cout << "m=" << m << " n=" << n << endl;
        vector<vector<int>> res(n, vector<int>(m));
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                res[i][j] = A[j][i];
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> vec = {{1,2,3}, {4,5,6}, {7,8,9}};

    vector<vector<int>> res = Solution().transpose(vec);

    for (vector<int> v: res)
    {
        for (int a: v)
            cout << a << " ";
    cout << endl;
    }

    return 0;
}

