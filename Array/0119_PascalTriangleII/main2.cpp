#include <iostream>
#include <vector>

using namespace std;

// Simulate Pascal Triangle only in O(rowIndex) space
// Time  Complexity: O(rowIndex^2)
// Space Complexity: O(rowIndex)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<vector<int>> res(2, vector<int>(rowIndex+1, 1)); 
        for (int i=2; i<=rowIndex; i++)
            for (int j=1; j<i; j++)
            {
                res[i&1][j] = res[(i-1)&1][j-1] + res[(i-1)&1][j];
            }

        return res[rowIndex&1];
    }
};

void print_vec(const vector<int>& vec)
{
    for (int e: vec)
        cout << e << " ";
    cout << endl;
}
int main()
{
    for (int i=0; i<10; i++)
        print_vec(Solution().getRow(i));

    return 0;
}

