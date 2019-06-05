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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;

        while (cur) {
            ListNode *post = cur->next;
            if (post && cur->val == post->val) {
                cur->next = post->next;
                ListNode * tmp = post;
                post = cur->next;
                delete tmp;
            }
            else
                cur = post;
        }
        return head;
    }
};

int main()
{

    return 0;
}

