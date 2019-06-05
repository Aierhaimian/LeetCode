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

// Using two pointer to create two list
// one element is less than x
// the othor is greater and equal x
// finally, we combine this two list
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummyNode1 = new ListNode(-1);
        ListNode *dummyNode2 = new ListNode(-1);

        ListNode *before = dummyNode1;
        ListNode *after = dummyNode2;

        ListNode *p = head;
        while (p) {
            if (p->val < x) {
                before->next = p;
                before = before->next;
            }
            else {
                after->next = p;
                after = after->next;
            }
            p = p->next;
        }

        before->next = dummyNode2->next;
        after->next = NULL;

        ListNode *ret = dummyNode1->next;
        delete dummyNode1;
        delete dummyNode2;
        return ret;
    }
};

int main()
{

    return 0;
}

