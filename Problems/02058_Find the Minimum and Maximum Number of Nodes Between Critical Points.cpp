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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1, -1};

        int pos = 1, firstFind = -1, lastFind = -1, MIN = INT_MAX;
        while(head->next->next)
        {
            if((head->val - head->next->val) * (long long)(head->next->val - head->next->next->val) < 0)
            {
                if(firstFind == -1) firstFind = pos;
                if(lastFind != -1) MIN = min(MIN, pos - lastFind);
                lastFind = pos;
            }

            head = head->next;
            pos++;
        }

        if(firstFind == lastFind) return {-1, -1};
        else return {MIN, lastFind - firstFind};
    }
};
