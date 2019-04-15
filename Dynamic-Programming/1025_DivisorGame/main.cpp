#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        bool flags = false;
        while (N > 1) {
            for (int i=1; i<N; i++)
            {
                if (N%i == 0)
                {
                    N -= i;
                    flags = !flags;
                    break;
                }
            }
        }
        return flags == true;
    }
};

int main()
{

    return 0;
}

