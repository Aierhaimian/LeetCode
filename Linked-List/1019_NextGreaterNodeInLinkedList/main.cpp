#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Using stack
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums = get_nums(head);
        return nextLargerNodes(nums);
    }

    vector<int> nextLargerNodes(const vector<int> &nums)
    {
        stack<int> s;
        vector<int> res(nums.size(), 0);
        for (size_t i=0; i<nums.size(); i++)
        {
            while (!s.empty() && nums[s.top()] < nums[i])
            {
                res[s.top()] = nums[i];
                s.pop();
            }

            s.push(i);
        }
        return res;
    }
private:
    vector<int> get_nums(ListNode *head)
    {
        vector<int> nums;
        ListNode *cur = head;
        while (cur != NULL)
        {
            nums.push_back(cur->val);
            cur = cur->next;
        }
        return nums;
    }
};

int main()
{

    return 0;
}

