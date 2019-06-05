#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    int binaryGap(int N) {
        vector<int> binary;
        while(N) {
            binary.push_back(N % 2);
            N /= 2;
        }

        int i = 0, j = 1;
        int distance = 0;
        while (j < binary.size()) {
            if (binary[i] == 1 && binary[j] == 1) {
                distance = max(distance, j - i);
                i = j;
                j++;
            }
            else if (binary[i] == 1)
                j ++;
            else {
                i ++;
                j ++;
            }
        }
        return distance;
    }
};

int main()
{

    return 0;
}

