#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Binary Search
// Time  Complexity: O(nlog(sum(weights)))
// Space Complexity: O(1)
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l,r;
        l = *max_element(weights.begin(), weights.end());  // 求weights中元素的最大值
        r = accumulate(weights.begin(), weights.end(), 0); // 求weights中元素的累加和

        while (l < r)
        {
            cout << "check " << l << " " << r << endl;
            int mid = (l+r)/2;
            if (ok(weights, mid, D)) // 船的载重为mid时，D天能不能拉完货物
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
private:
    bool ok(const vector<int>& weights, int C, int D)
    {
        int d = 0, cur = 0;
        for (int w: weights)
        {
            if (cur + w <= C) cur += w;
            else
                d ++, cur = w;
        }
        if (cur) d ++;
        return d <= D;
    }
};

int main()
{
    vector<int> weight1 = {1,2,3,4,5,6,7,8,9,10};
    int D1 = 5;
    cout << Solution().shipWithinDays(weight1, D1) << endl; // 15
    
    vector<int> weight2 = {1,2,3,1,1};
    int D2 = 4;
    cout << Solution().shipWithinDays(weight2, D2) << endl; // 3
    return 0;
}

