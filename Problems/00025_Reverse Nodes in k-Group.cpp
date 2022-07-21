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
    ListNode *revHelper(ListNode *&head, int k, bool alpha = true)
    {
        if(head == nullptr)
            return nullptr;

        ListNode *rev = nullptr, *tmp;
        int cpy = k;
        while(head && k--)
        {
            tmp = head;
            head = head->next;
            tmp->next = rev;
            rev = tmp;
        }

        if((k != -1 && k != 0) && alpha) return revHelper(rev, cpy, false);
        else return rev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

        ListNode *ans, *endOfPartRev = head, *tmp;
        ans = revHelper(head, k);

        while(head)
        {
            tmp = head;
            endOfPartRev->next = revHelper(head, k);
            endOfPartRev = tmp;
        }

        return ans;
    }
};
