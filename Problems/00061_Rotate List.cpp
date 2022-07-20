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
    // vector<ListNode *> v;
public:
    // Solution(){ v.resize(501); }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        ListNode *lol = new ListNode(0, head), *ptr; // v[0] = lol;
        ListNode *prev = lol;
        // int n = -1;
        for(int i=0;i<k;i++)
        {
            prev = prev->next;
            if(!prev->next) return rotateRight(head, k % (i + 1)); // i + 1 is our current size
            // if(!prev->next){ n = i; break; }
            // v[i + 1] = prev = prev->next;
        }

        ptr = lol;
        while(prev->next) ptr = ptr->next, prev = prev->next;

        // prev is our tail now
        prev->next = head;
        head = ptr->next;
        ptr->next = nullptr;
        return head;

        /* if(n == -1)
        {
            ptr = lol;
            while(prev->next) ptr = ptr->next, prev = prev->next;

            // prev is our tail now
            prev->next = head;
            head = ptr->next;
            ptr->next = nullptr;
            return head;
        }
        else
        {
            k = k % n; // k is min 0
            if(k == 0) k = n;
            k = n - k; // this is the predecessor node
            prev = v[k];

            v[n]->next = head;
            head = prev->next;
            prev->next = nullptr;
            return head;
        } */
    }
};
