#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 流式数据
// 第一种：保存前k个最大值，sort
// Time  Complexity: O(N*klogk)
// Space Complexity: O(N)
//
// 第二种：优先队列MinHeap: the heap size is k
// Time  Complexity: O(N*(1 or logk)) -> O(Nlogk)
// Space Complexity: O(k)
//
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
        :_k(k)
    {
        if (nums.size()) {
            sort(nums.rbegin(), nums.rend());
            for (int i=0; i<(_k < nums.size() ? _k : nums.size()); i++)
                pri_que.push(nums[i]);
        }
    }

    int add(int val) {
        if (pri_que.size() < _k)
            pri_que.push(val);
        else if (pri_que.top() < val) {
            pri_que.pop();
            pri_que.push(val);
        }
        return pri_que.top();
    }
private:
    // 定义一个小顶堆
    priority_queue<int, vector<int>, greater<int>> pri_que;
    int _k;
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{

    return 0;
}

