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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return head;

        ListNode *oddHead = head;
        ListNode *evenHead = head->next;
        
        ListNode *odd = oddHead;
        ListNode *even = evenHead;

        while (even && even->next) {
            odd->next = odd->next->next;
            odd = odd->next;

            even->next = even->next->next;
            even = even->next;
        }

        odd->next = evenHead;
        return oddHead;
    }
};

int main()
{

    return 0;
}

