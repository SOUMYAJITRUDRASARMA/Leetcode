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

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *n = head;
        while(n){ while(n->next && n->val == n->next->val) deleteAfter(n); n = n->next; }

        return head;
    }
};
