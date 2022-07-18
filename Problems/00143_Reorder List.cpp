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
    inline void insertEnd(ListNode *n, ListNode *&tail)
    {
        tail->next = n;
        tail = n;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;

        ListNode *n = head, *tail = head;
        deque<ListNode *> dq;
        while(n = n->next) dq.push_back(n);

        while(dq.size() > 1)
        {
            n = dq.back(); dq.pop_back();
            insertEnd(n, tail);
            n = dq.front(); dq.pop_front();
            insertEnd(n, tail);
        }

        if(!dq.empty())
            insertEnd(dq.front(), tail);

        tail->next = nullptr;
    }
};
