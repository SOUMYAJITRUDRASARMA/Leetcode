/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    inline void insertEnd(ListNode *n, ListNode *&head, ListNode *&tail)
    {
        if(!head) head = tail = n;
        else tail->next = n, tail = n;
    }

    ListNode* partition(ListNode* head, int x) {
        ListNode *h1, *t1, *h2, *t2, *n;
        h1 = t1 = h2 = t2 = nullptr;
        while(head)
        {
            n = head;
            head = head->next;

            if(n->val < x) insertEnd(n, h1, t1);
            else insertEnd(n, h2, t2);
        }

        if(!h1) return h2;
        if(!h2) return h1;

        t1->next = h2;
        t2->next = nullptr;

        return h1;
    }
};
