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

// My solution
class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *resNode = new ListNode(-1);
        ListNode *l = resNode;

        ListNode *p = l1;
        ListNode *q = l2;
        int cnt = 0;
        while (p && q) {
            ListNode *newNode = new ListNode(-1);
            int tmp = p->val + q->val + cnt;
            cnt = 0;
            if (tmp >= 10) {
                newNode->val = tmp % 10;
                cnt = tmp / 10;
            }
            else
                newNode->val = tmp;

            l->next = newNode;
            l = newNode;

            p = p->next;
            q = q->next;
        }


        int ccnt1 = 0;
        if (p) {
            l->next = p;
            while (p) {
                int tmp = p->val + cnt + ccnt1;
                cnt = 0;
                ccnt1 = 0;
                if (tmp >= 10) {
                    p->val = tmp % 10;
                    ccnt1 = tmp / 10;
                    p = p->next;
                }
                else {
                    p->val = tmp;
                    break;
                }
            }
        }

        int ccnt2 = 0;
        if (q) {
            l->next = q;
            while (q) {
                int tmp = q->val + cnt + ccnt2;
                cnt = 0;
                ccnt2 = 0;
                if (tmp >= 10) {
                    q->val = tmp % 10;
                    ccnt2 = tmp / 10;
                    q = q->next;
                }
                else {
                    q->val = tmp;
                    break;
                }
            }
        }

        if (cnt) {
            while (l->next)
                l = l->next;
            ListNode *newNode = new ListNode(cnt);
            l->next = newNode;
        }

        if (ccnt1) {
            while (l->next)
                l = l->next;
            ListNode *newNode = new ListNode(ccnt1);
            l->next = newNode;
        }

        if (ccnt2) {
            while (l->next)
                l = l->next;
            ListNode *newNode = new ListNode(ccnt2);
            l->next = newNode;
        }

        ListNode *ret = resNode->next;
        delete resNode;
        return ret;
    }
};

// The solution for Big brother
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preHead(0);
        ListNode *p = &preHead;
        int extra = 0;
        while (l1 || l2 || extra)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        return preHead.next;
    }
};

int main()
{

    return 0;
}

