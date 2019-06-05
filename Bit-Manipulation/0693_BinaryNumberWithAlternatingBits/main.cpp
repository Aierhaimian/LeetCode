#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> binary;
        int tmp = n;
        while (tmp) {
            binary.push_back(tmp%2);
            tmp /= 2;
        }
        for (int i=0; i<binary.size()-1; i++) {
            if (binary[i] == binary[i+1])
                return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}

