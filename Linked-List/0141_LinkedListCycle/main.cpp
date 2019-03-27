#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Time  Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) { // 不要忘了fast走两步，那么需要验证fast及fast->next是否为空
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }

        return false;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

