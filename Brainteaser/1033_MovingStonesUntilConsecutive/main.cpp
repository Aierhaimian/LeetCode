#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int temp;
        if(a>b) temp=a,a=b,b=temp;
        if(b>c) temp=b,b=c,c=temp;
        if(a>b) temp=a,a=b,b=temp;
        int max = (b-1-a) + (c-(b+1));
        int min = (b-1 == a ? 0 : 1) + (b+1 == c ? 0 : 1);
        if (b-1 - a == 1 || c- (b+1) == 1)
            min = 1;
        vector<int> res;
        res.push_back(min);
        res.push_back(max);
        return res;
    }
};

int main()
{

    return 0;
}

