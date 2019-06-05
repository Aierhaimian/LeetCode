#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Build the correct order of heights by sorting 
// another array, then compare the two arrays.
// Time  Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        if (heights.size() <= 1)
            return 0;
        vector<int> tmp(heights);
        sort(tmp.begin(), tmp.end());
        int minNum = 0;
        for (int i=0; i<heights.size(); i++) {
            if (heights[i] != tmp[i])
                minNum ++;
        }
        return minNum;
    }
};

int main()
{

    return 0;
}

