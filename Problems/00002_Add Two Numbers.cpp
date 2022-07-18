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
    inline void insertBack(ListNode *n, ListNode *&head, ListNode *&tail)
    {
        if(!head) head = tail = n;
        else tail->next = n, tail = n;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head, *tail, *n;
        head = tail = nullptr;

        int sum, carry = 0;
        while(l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            carry = sum / 10, sum %= 10;
            insertBack(new ListNode(sum), head, tail);
            l1 = l1->next, l2 = l2->next;
        }

        while(l1)
        {
            sum = l1->val + carry;
            carry = sum / 10, sum %= 10;
            insertBack(new ListNode(sum), head, tail);
            l1 = l1->next;
        }

        while(l2)
        {
            sum = l2->val + carry;
            carry = sum / 10, sum %= 10;
            insertBack(new ListNode(sum), head, tail);
            l2 = l2->next;
        }

        if(carry) insertBack(new ListNode(carry), head, tail);

        return head;
    }
};
