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
    ListNode* middleNode(ListNode* head) {
        if(!head) return nullptr;
        ListNode *cur = head;
        while(head && head->next)
        {
            cur = cur->next;

            head = head->next;
            head = head->next;
        }

        return cur;
    }
};
