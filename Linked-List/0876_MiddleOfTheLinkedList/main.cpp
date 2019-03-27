#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* p = head;
        int i = 1, j = 0;
        while (p) {
            j++;
            p = p->next;
        }
        
        if (j == 1) return head;

        p = head;
        while (i < j) {
            i ++;
            j --;
            p = p->next;
        }

        if (i == j) return p;
        else return p;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

