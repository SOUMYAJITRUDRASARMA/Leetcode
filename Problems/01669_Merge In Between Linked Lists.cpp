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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        b = b - a + 2; // this many nodes to skip, +2 for extremities
        ListNode *ans = list1, *end;

        while(--a) list1 = list1->next;
        end = list1;
        while(b--) end = end->next;

        list1->next = list2;
        while(list2->next) list2 = list2->next;
        list2->next = end;

        return ans;
    }
};
