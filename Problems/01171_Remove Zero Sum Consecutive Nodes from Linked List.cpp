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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return head;

        unordered_map<int, ListNode *> m; // sum to nodes

        int sum = 0;
        ListNode *n = head;
        bool isDel = false;
        while(n)
        {
            sum += n->val;
            if(!sum)
                return removeZeroSumSublists(n->next);
            else if(m.find(sum) != m.end())
            {
                isDel = true;
                m[sum]->next = n->next; // range deleted
                break;
            }
            else m[sum] = n;

            n = n->next;
        }

        if(isDel) return removeZeroSumSublists(head); // needs another filter, we cannot delete from map which range was deleted, their sum - would be O(n^2) anyways for manual backtraversal, rather fresh start
        else return head;
    }
};
