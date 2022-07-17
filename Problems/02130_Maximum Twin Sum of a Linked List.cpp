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
    int len(ListNode* head)       // len == length of linkedlist
    {
        ListNode * temp = head;
        int count= 0;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }

    int pairSum(ListNode* head) {
        ListNode* temp = head;
        int st = len(temp);      // Obtaining the length of the linkedlist
        stack<int> s;   // using a stack
        int max_sum = 0;
        for(int i = 0;i<st;i++)
        {
            if(i<st/2)              //for the first half , push element in stack
            {
                s.push(head->val);
            }
            else                    // for other half take out the topmost element , stores and compare it withprevious maximum
            {
                int sum = s.top()+head->val;
                max_sum=max(max_sum,sum);
                s.pop();
            }
            head=head->next;
        }
        return max_sum;     // return max sum

    }
};
