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

    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;

        ListNode *h1, *t1, *h2, *t2, *n;
        h1 = t1 = h2 = t2 = nullptr;
        bool isOdd = true;
        while(head)
        {
            n = head;
            head = head->next;

            if(isOdd) insertBack(n, h1, t1);
            else insertBack(n, h2, t2);

            isOdd = !isOdd;
        }

        t1->next = h2;
        if(t2) t2->next = nullptr;
        return h1;
    }
};
