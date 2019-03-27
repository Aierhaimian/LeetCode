#include <iostream>
#include <vector>

using namespace std;

// Time Limit Exceeded
// Time  Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt = 0;
        for (int i=0; i<time.size()-1; i++)
        {
            for (int j=i+1; j<time.size(); j++)
            {
                if ((time[i] + time[j])%60 == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

