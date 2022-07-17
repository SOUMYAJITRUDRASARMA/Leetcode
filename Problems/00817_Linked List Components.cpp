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
    int findRep(int i, vector<int> &v)
    {
        if(v[i] < 0) return i;
        else return v[i] = findRep(v[i], v);
    }

    bool unionDS(int a, int b, vector<int> &v)
    {
        int aRep, bRep;
        aRep = findRep(a, v);
        bRep = findRep(b, v);

        if(aRep == bRep) return false;

        int aSize, bSize;
        aSize = -v[aRep];
        bSize = -v[bRep];

        if(aSize <= bSize)
        {
            v[aRep] = bRep;
            v[bRep] = -(aSize + bSize);
        }
        else
        {
            v[bRep] = aRep;
            v[aRep] = -(aSize + bSize);
        }

        return true;
    }

    int numComponents(ListNode* head, vector<int>& nums) {
        // dsu
        int n = nums.size();
        if(!head) return n;

        vector<int> v(n, -1);
        unordered_map<int, int> m; // value to position
        for(int i=0;i<n;i++) m[nums[i]] = i;
        int a, b;
        while(head->next)
        {
            a = head->val, b = head->next->val;
            if(m.find(a) != m.end() && m.find(b) != m.end())
            {
                if(findRep(m[a], v) != findRep(m[b], v))
                    unionDS(m[a], m[b], v), n--;
            }

            head = head->next;
        }

        return n;
    }
};
