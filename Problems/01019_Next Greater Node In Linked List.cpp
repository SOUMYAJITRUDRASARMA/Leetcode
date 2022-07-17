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
    vector<int> nextLargerNodes(ListNode* head) {
        // as this is LL, lets not do reverse iteration and backwards stack
        // ie. for every element, pop out stack till empty or greater value is found -> set -1/0 or that val acc
        // finally push the element into stack

        // instead here for forward iteration, we store Node * into stack
        // for every greater value found, pop stack and set the node's next value
        // final remaining stack elements have no greater value, so -1/0 is set

        stack<pair<int, int>> st; // position
        vector<int> ans(1e4 + 1, 0); // position, data
        int pos = 0;
        while(head)
        {
            /* while(!st.empty() && st.top()->val < head->val)
                st.top()->greater = head, st.pop(); */
            while(!st.empty() && st.top().second < head->val)
                ans[st.top().first] = head->val, st.pop();

            st.push( {pos, head->val} );
            head = head->next;
            pos++;
        }

        ans.resize(pos);
        return ans;
    }
};
