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
    inline void deleteAfter(ListNode *n)
    {
        ListNode *tmp = n->next;
        n->next = tmp->next;
        delete tmp;
    }

    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        ListNode *n = head;
        while(n->next){ while(n->next && n->next->val == val) deleteAfter(n); if(n->next) n = n->next; }
        if(head->val == val){ n = head; head = n->next; delete n; }
        return head;
    }
};
