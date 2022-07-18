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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Lets point to predecessor of nth node
        ListNode *lol = new ListNode(0, head), *first = lol, *second = head;
        while(n--) second = second->next;
        while(second) first = first->next, second = second->next;
        first->next = first->next->next;
        return lol->next;
    }
};
