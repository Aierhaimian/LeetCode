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

// Recursive
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution1 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode *pre = dummyNode; // pre是m结点的前一个结点
        for (int i=0; i<m-1; i++, pre = pre->next);

        ListNode *tail = pre->next; // 反转m-n的结点后此结点就是最后一个结点
        ListNode *left; // 反转后此结点指向n结点的后一个结点
        pre->next = reverse(pre->next, n-m, left);
        tail->next = left;

        ListNode *returnNode = dummyNode->next;
        delete dummyNode;
        return returnNode;
    }
private:
    ListNode *reverse(ListNode *head, int index, ListNode *&left) {
        if (index == 0) {
            left = head->next;
            return head;
        }

        ListNode *tail = head->next;
        ListNode *ret = reverse(head->next, index-1, left);
        tail->next = head;

        return ret;
    }
};

// Non-Recursive
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        
        ListNode *pre = dummyNode;
        for (int i=0; i<m-1; i++, pre = pre->next);

        ListNode *tail = pre->next;
        ListNode *left = tail;
        pre->next = reverse(pre->next, n-m, left);
        if (left != tail) tail->next = left;

        ListNode *ret = dummyNode->next;
        delete dummyNode;
        return ret;
    }
private:
    ListNode *reverse(ListNode *head, int n, ListNode *&left) {
        if (!head || !head->next || !n)
            return head;

        ListNode *pre = head;
        ListNode *cur = head->next;
        while (n--) {
            ListNode *post = cur->next;

            cur->next = pre;
            pre = cur;
            cur = post;
        }

        left = cur;
        return pre;
    }
};

int main()
{

    return 0;
}

