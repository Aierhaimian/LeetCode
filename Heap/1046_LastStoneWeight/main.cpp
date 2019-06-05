#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 使用最大堆，每次都可以获得最大的石头
// 将其拿出，凑够两个相互抵消，抵消剩下的
// 在加入最大堆，直到堆中只有一个石头
// Time  Complexity: O()
// space Complexity: O()
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int s: stones)
            pq.push(s);
        while (!pq.empty() && pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if (x == y)
                continue;
            else
                pq.push(abs(x-y));
        }

        if (pq.empty())
            return 0;
        return pq.top();
    }
};

int main()
{

    return 0;
}

