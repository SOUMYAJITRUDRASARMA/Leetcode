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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *n = insertionSortList(head->next);
        if(head->val <= n->val)
        {
            head->next = n;
            return head;
        }
        else
        {
            ListNode *prev = n;
            while(prev->next && prev->next->val < head->val) prev = prev->next;
            head->next = prev->next;
            prev->next = head;
            return n;
        }
    }
};
