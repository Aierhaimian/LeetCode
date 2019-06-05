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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;

        ListNode *p = dummyNode;
        while(p->next && p->next->next) {
            ListNode *node1 = p->next;
            ListNode *node2 = p->next->next;
            //ListNode *post = node2->next;

            node1->next = node2->next;
            node2->next = node1;
            p->next = node2;

            p = node1;
        }
        ListNode *returnNode = dummyNode->next;
        delete dummyNode;
        return returnNode;
    }
};

int main()
{

    return 0;
}

