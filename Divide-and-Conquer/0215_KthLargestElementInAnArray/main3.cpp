#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Using Min Heap to store the k largest elements
// Time  Complexity: O(nlogk)
// Space Complexity: O(k)
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater_equal<int>> pq;
        for (int e: nums)
        {
            if (pq.size() != k)
                pq.push(e);
            else if (e > pq.top()) 
            {
                pq.pop();
                pq.push(e);
            }
        }

        return pq.top();
    }
};

int main()
{

    return 0;
}

