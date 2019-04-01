#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size();
        if (target >= letters[r-1]) return letters[l];
        if (target < letters[l]) return letters[l];

        while (l < r)
        {
            int mid = l + (r - l)/2;
            if (target <= letters[mid])
                r = mid;
            else
                l = mid + 1;
        }
        while (l != letters.size() && letters[l] == target)
            l ++; // for seq like a a a a b b b b 

        return letters[l%(letters.size())];

    }
};

int main()
{

    return 0;
}

