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

    ListNode* mergeNodes(ListNode* h) {
        int sum = 0;
        ListNode *head, *tail;
        head = tail = nullptr;

        h = h->next;
        while(h)
        {
            if(h->val == 0) insertBack(new ListNode(sum), head, tail), sum = 0;
            else sum += h->val;
            h = h->next;
        }

        return head;
    }
};
