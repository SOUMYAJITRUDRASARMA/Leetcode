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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return head;

        ListNode *lol = new ListNode(0, head), *slow = lol, *fast = lol->next;
        slow = fast = lol;
        while(fast->next && fast->next->next) slow = slow->next, fast = fast->next->next;
        // deleting after slow
        slow->next = slow->next->next;
        return lol->next;
    }
};
