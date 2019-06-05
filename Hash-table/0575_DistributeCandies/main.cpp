#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int n = candies.size();
        unordered_set<int> kinds;
        for (int i=0; i<n; i++)
            kinds.insert(candies[i]);
        return kinds.size() < n/2 ? kinds.size() : n/2;
    }
};

int main()
{

    return 0;
}

