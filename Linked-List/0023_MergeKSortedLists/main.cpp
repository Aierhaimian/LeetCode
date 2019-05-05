#include <iostream>
#include <vector>
#include <queue>
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

// 将k个已排序的链表合并成一个排好序的链表输出

// Linear Compare each ListNode
// Time  Complexity: O(k*n) where k is len(lists) and n is the node size
// Space Complexity: O(1)
class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == NULL)
            return NULL;
        ListNode *dummyHead = new ListNode(-1); // 链表刷题套路：搞个头结点
        ListNode *curNode = dummyHead;

        int finished = 0; // 统计已经merge完的链表数
        for (ListNode *node : lists) // 可能有初始空链表
            if (node == NULL)
                finished ++;

        while (finished < lists.size()) {
            ListNode *nextNode = NULL;
            int nextIndex = -1;
            for (int i=0; i<lists.size(); i++) { // 找出lists中当前节点的最小值
                if (lists[i] != NULL) {
                    if (nextIndex == -1 || lists[i]->val < nextNode->val) {
                        nextNode = lists[i];
                        nextIndex = i;
                    }
                }
            }
            assert(nextIndex != -1 && nextNode != NULL);
            lists[nextIndex] = lists[nextIndex]->next; // 最小节点已merge，指向下一个节点
            if (lists[nextIndex] == NULL)
                finished ++; // 又merge完一个

            curNode->next = nextNode;
            nextNode->next = NULL;
            curNode = curNode->next; // merge到主链
        }
        ListNode *ret = dummyHead->next; // 链表刷题套路
        delete dummyHead;
        return ret;
    }
};

// Merge List one by one 
// Time  Complexity: O(k*n)
// Space Complexity: O(1)
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == NULL) return NULL;
        ListNode *ret = NULL;
        for (ListNode *list: lists)
            ret = merge(ret, list);
        return ret;
    }
private:
    ListNode* merge(ListNode *res, ListNode *list) {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *curNode = dummyHead;

        while (res != NULL && list != NULL) {
            if (res->val < list->val) {
                curNode->next = res;
                res = res->next;
            }
            else {
                curNode->next = list;
                list = list->next;
            }
            curNode = curNode->next;
            curNode->next = NULL;
        }
        if (res)
            curNode->next = res;
        if (list)
            curNode->next = list;
        ListNode *ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};

class CompareListNode {
public:
    bool operator()(ListNode *l1, ListNode *l2) {
        return l1->val > l2->val;
    }
};

// Using Priority Queue to compare each ListNode
// Time  Complexity: O(nlogk)
// Space Complexity: O(1)
class Solution3 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;

        ListNode *dummyNode = new ListNode(-1);
        ListNode *curNode = dummyNode;

        // 优先队列
        priority_queue<ListNode *, vector<ListNode*>, CompareListNode> q;
        for (ListNode *list: lists)
            if (list != NULL)
                q.push(list);

        while (!q.empty()) {
            ListNode *nextNode = q.top();
            q.pop();

            curNode->next = nextNode;
            if (nextNode->next != NULL)
                q.push(nextNode->next);

            nextNode->next = NULL;
            curNode = curNode->next;
        }
        ListNode *ret = dummyNode->next;
        delete dummyNode;
        return ret;
    }
};

// Divide and Conquer
// Using Bottom-Up Merge
// Time  Complexity: O(nlogk)
// Space Complexity: O(logk)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;

        while (lists.size() > 1) {
            int index = 0;
            for (int i=0; i<lists.size(); i+=2) {
                if (i+1 == list.size())
                    lists[index] = lists[i];
                else
                    lists[index] = merge(lists[i], lists[i+1]);
                index ++;
            }

            while (lists.size() > index)
                lists.pop_back();
        }
        return lists[0];
    }
private:
    ListNode* merge(ListNode *list1, ListNode *list2) {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *curNode = dummyHead;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                curNode->next = list1;
                list1 = list1->next;
            }
            else {
                curNode->next = list2;
                list2 = list2->next;
            }

            curNode = curNode->next;
            curNode->next = NULL;
        }

        if (list1)
            curNode->next = list1;
        if (list2)
            curNode->next = list2;

        ListNode *ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};

int main()
{

    return 0;
}

