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
    ListNode* getMiddle(ListNode* head) {
        if(!head) return head;

        ListNode *lol = new ListNode(0, head), *slow = lol, *fast = lol->next;
        while(fast->next && fast->next->next) slow = slow->next, fast = fast->next->next;
        slow = slow->next;
        delete lol;
        return slow;
    }

    inline void insertBack(ListNode *n, ListNode *&head, ListNode *&tail)
    {
        if(!head) head = tail = n;
        else tail->next = n, tail = n;
    }

    ListNode *mergeSortedLists(ListNode *l1, ListNode *l2)
    {
        if(!l1 && !l2) return nullptr;
        else if(l1 && !l2) return l1;
        else if(!l1 && l2) return l2;

        ListNode *head, *tail, *n;
        head = tail = nullptr;
        while(l1 && l2)
        {
            if(l1->val < l2->val) n = l1, l1 = l1->next, insertBack(n, head, tail);
            else n = l2, l2 = l2->next, insertBack(n, head, tail);
        }

        if(l1) tail->next = l1;
        else tail->next = l2;

        return head;
    }

    ListNode* sortList(ListNode* head) {
        // merge sort
        if(!head || !head->next) return head;

        ListNode *l1, *l2, *mid;
        mid = getMiddle(head);
        l1 = head;
        l2 = mid->next;
        mid->next = nullptr;

        if(l1->next) l1 = sortList(l1);
        if(l2->next) l2 = sortList(l2);

        return mergeSortedLists(l1, l2);
    }
};
