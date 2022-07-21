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
    void insertBack(ListNode *n, ListNode *&head, ListNode *&tail)
    {
        if(!head) head = tail = n;
        else tail->next = n, tail = n;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if(!l1 && !l2) return nullptr;
        else if(l1 && !l2) return l1;
        else if(!l1 && l2) return l2;

        ListNode *head, *tail, *n;
        head = tail = nullptr;

        while(l1 && l2)
        {
            if(l1->val <= l2->val) n = l1, l1 = l1->next, insertBack(n, head, tail);
            else n = l2, l2 = l2->next, insertBack(n, head, tail);
        }

        if(l1) tail->next = l1;
        else tail->next = l2;

        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        int end = lists.size() - 1;
        while(end > 0)
        {
            for(int i=0;i<=(end-1)/2;i++)
                lists[i] = mergeTwoLists(lists[i], lists[end - i]);

            end /= 2;
        }

        return lists[0];
    }
};
