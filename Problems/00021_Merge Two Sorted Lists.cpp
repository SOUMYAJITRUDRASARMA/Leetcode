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
        if(!head && !tail) head = tail = n;
        else tail->next = n, tail = n;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return nullptr;
        else if(!list1 && list2) return list2;
        else if(list1 && !list2) return list1;

        ListNode *head, *tail, *n;
        head = tail = nullptr;

        while(list1 && list2)
        {
            if(list1->val < list2->val) n = list1, list1 = n->next, insertBack(n, head, tail);
            else n = list2, list2 = n->next, insertBack(n, head, tail);
        }

        if(list1) tail->next = list1;
        else tail->next = list2;

        return head;
    }
};
