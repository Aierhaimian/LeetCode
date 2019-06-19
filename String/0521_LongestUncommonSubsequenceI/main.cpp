#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) return -1;
        return max(a.size(), b.size());
    }
};

int main()
{

    return 0;
}

