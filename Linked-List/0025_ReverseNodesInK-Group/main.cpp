#include <iostream>
#include <vector>
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

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node = head;
        for (int i=0; i<k; i++) {
            if (!node)
                return head; // list length less than k, do nothing
            node = node->next;
        }

        ListNode *new_head = reverse(head, node);
        head->next = reverseKGroup(node, k);
        return new_head;
    }
private:
    ListNode *reverse(ListNode *head, ListNode *end) {
        ListNode *pre = end;

        while (head != end) {
            ListNode *tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }

        return pre;
    }
};

int main()
{

    return 0;
}

