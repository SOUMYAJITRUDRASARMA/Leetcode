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
    void helper(ListNode *n, int &ans, int &mask)
    {
        if(!n) return;
        helper(n->next, ans, mask);
        if(n->val) ans += mask;
        mask = mask << 1;
    }

    int getDecimalValue(ListNode* head) {
        int ans = 0, mask = 1;
        helper(head, ans, mask);
        return ans;
    }
};
