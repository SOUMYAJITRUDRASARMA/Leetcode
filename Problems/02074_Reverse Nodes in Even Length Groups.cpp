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
    // Reverse function to reverse the even length parts of linked list, and returns
// the new head and tail of reversed linked list
pair<ListNode*,ListNode*> reverse(ListNode *head)
{
    pair<ListNode*,ListNode*>ans;
    ans.second = head;

    ListNode *p = head,*q = nullptr,*r = nullptr;

    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
    ans.first = head;

    return ans;
}

ListNode *helper(ListNode *head,int k)
{
     if(head == nullptr)
    {
        return nullptr;
    }

    ListNode *p = head,*q = head;
    ListNode *nhead = nullptr,*ntail = nullptr;
    int i = 1;

    while(q && i < k)
    {
        q = q->next;
        i++;
    }

    ListNode *nextHead = nullptr;
    if(q)
    {
        nextHead = q->next;
        q->next = nullptr;
    }

	// important condition for reverse ->
	// i) k is even (even length portion) and q!=nullptr to ensure that this portion is not
	// the last portion , (as last portion may have incomplete nodes)

	// ii) If k is not even but the last portion has even no. of nodes
	// (i-1)%2 == 0 for even no. of nodes, i is increased +1 more before exit so -1 is done
	// and q == nullptr to ensure that this is the incomplete nodes portion the last portion

    if((k%2 == 0 && q!=nullptr) || (q == nullptr && (i-1)%2 == 0))
    {
        pair<ListNode*,ListNode*> ans = reverse(p);
        nhead = ans.first;
        ntail = ans.second;
    }
    else
    {
        nhead = p;
        ntail = q;
    }

    if(ntail)
    {
        ntail->next = helper(nextHead,k+1);
		// k+1 for next portion
    }

    return nhead;
}

ListNode* reverseEvenLengthGroups(ListNode* head) {
    if(head == nullptr)
    {
        return nullptr;
    }

    return helper(head,1);
}
};
