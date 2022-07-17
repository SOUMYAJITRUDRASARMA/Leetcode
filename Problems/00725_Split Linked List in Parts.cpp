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
    inline int length(ListNode *n)
    {
        int cnt = 0;
        while(n) cnt++, n = n->next;
        return cnt;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // If there are N nodes in the list, and k parts, then every part has N/k elements, except the first N%k parts have an extra one
        vector<ListNode *> ans(k, nullptr);
        if(!head) return ans;

        ListNode *tmp;
        int n = length(head), ptr = 0, cnt = n % k, num = n / k + 1;
        while(cnt--)
        {
            ans[ptr++] = head;
            for(int i=1;i<num;i++) head = head->next;
            tmp = head;
            head = head->next;
            tmp->next = nullptr;
        }

        cnt = k - n % k, num = n / k;
        if(num)
        while(cnt--)
        {
            ans[ptr++] = head;
            for(int i=1;i<num;i++) head = head->next;
            tmp = head;
            head = head->next;
            tmp->next = nullptr;
        }

        return ans;
    }
};
