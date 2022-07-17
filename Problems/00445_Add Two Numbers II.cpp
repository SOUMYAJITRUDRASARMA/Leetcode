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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode *> *s1, *s2;
        s1 = new stack<ListNode *>();
        s2 = new stack<ListNode *>();

        ListNode *n = l1, *n1, *n2;
        while(n) s1->push(n), n = n->next;
        n = l2;
        while(n) s2->push(n), n = n->next;

        if(s1->size() < s2->size()) swap(s1, s2), swap(l1, l2);

        int carry = 0;
        while(!s1->empty() && !s2->empty())
        {
            n1 = s1->top(); s1->pop();
            n2 = s2->top(); s2->pop();

            n1->val = n1->val + n2->val + carry;
            carry = n1->val / 10;
            n1->val %= 10;
        }

        if(carry)
        {
            // end carry condition
            while(carry && !s1->empty())
            {
                n1 = s1->top(); s1->pop();

                n1->val = n1->val + carry;
                carry = n1->val / 10;
                n1->val %= 10;
            }

            if(carry)
            {
                // case of 9999... + 1...
                ListNode *alpha = new ListNode(1);
                alpha->next = l1;
                l1 = alpha;
            }
        }

        return l1;
    }
};
