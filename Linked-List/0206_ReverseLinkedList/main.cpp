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

// My try use 3 pointer
// The ugly code
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode *cur = head;
        ListNode *pre = cur;
        ListNode *post = head->next;
        while (post->next != NULL) {
            cur = post;
            post = post->next;
            cur->next = pre;
            pre = cur;
        }

        post->next = cur;
        head->next = NULL;
        head = post;

        return head;
    }
};

// The beautiful code.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur != NULL) {
            ListNode *post = cur->next;
            
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        return pre;
    }
};

int main()
{

    return 0;
}

