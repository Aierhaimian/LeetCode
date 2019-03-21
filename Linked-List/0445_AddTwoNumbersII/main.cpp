#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// my version, bad effective!
class Solution {
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* res = new ListNode(0);
       if (l1 == NULL && l2 == NULL) return l1;
       if (l1 != NULL && l2 == NULL) return l1;
       if (l1 == NULL && l2 != NULL) return l2;


       vector<int> vec1, vec2, vec;
       ListNode* p = l1;
       ListNode* q = l2;

       while (p != NULL)
       {
           vec1.push_back(p->val);
           p = p->next;
       }

       while (q != NULL)
       {
           vec2.push_back(q->val);
           q = q->next;
       }

       int m = vec1.size() - 1;
       int n = vec2.size() - 1;

       int c = 0;
       while (m >= 0 && n >= 0)
       {
           int tmp = vec1[m--] + vec2[n--] + c;
           if (tmp > 9)
           {
               tmp %= 10;
               c = 1;
           }
           else
               c = 0;
           vec.push_back(tmp);
       }


       int c1 = 0; //fix bug just like input: [9,9] [1] output: [1,0,0]
       while (m >= 0) {
           int tmp = vec1[m--] + c + c1;
           c = 0;
           if (tmp > 9)
           {
               tmp%=10;
               c1 = 1;
           }
           else
               c1 = 0;
           vec.push_back(tmp);
       }

       if (c1 == 1) vec.push_back(1);

       int c2 = 0;
       while (n >= 0) {
           int tmp = vec2[n--] + c + c2;
           c = 0;
           if (tmp > 9)
           {
               tmp %= 10;
               c2 = 1;
           }
           else
               c2 = 0;
           vec.push_back(tmp);
       }
       if (c2 == 1) vec.push_back(1);

       if (c == 1) // fix bug just like input: [5] [5] output: [1,0]
           vec.push_back(1);

       ListNode* l = res;
       for (int i=vec.size() - 1; i>=0; i--)
       {
           ListNode* tmp = new ListNode(vec[i]);
           l->next = tmp;
           l = l->next;
       }

       return res->next;
   }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

