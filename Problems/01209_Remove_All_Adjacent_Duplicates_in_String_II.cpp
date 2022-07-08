// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

// Remove all K consecutive characters from a string and form a new string, then repeat
// the process for the new string and so on until no K consecutive characters can be found
// and finally return the string

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MOD 1000000007

class Solution {
public:
    void PrintStack(stack<char> s)
    {
    // If stack is empty then return
    if (s.empty())
        return;


    char x = s.top();

    // Pop the top element of the stack
    s.pop();

    // Recursively call the function PrintStack
    PrintStack(s);

    // Print the stack element starting
    // from the bottom
    cout << x << " ";

    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
    }

    string removeDuplicates(string s, int k) {
        if(k==1)
            return string("");

        stack<char> st, st2;
        for(char ch: s)
            st.push(ch);

        int cnt = 0;
        char prev = '0', ch;
        while(!st.empty())
        {
            ch = st.top(); st.pop();
            if(ch == prev)
                cnt ++;
            else
            {
                cnt = 1;
                prev = ch;
            }

            if(cnt == k)
            {
                for(int i=1;i<=k-1;i++) st2.pop();

                 // cout<<"{  "; PrintStack(st); cout<<endl;
                 // PrintStack(st2); cout<<"  }"<<endl<<endl;

                if((!st.empty()) && (!st2.empty()))
                if(st.top() == st2.top())
                {
                    char chNeeded = st2.top();
                    while(st2.top() == chNeeded)
                    {
                        st.push(st2.top()); st2.pop();
                        if(st2.empty())
                            break;
                    }
                }

                cnt = 0;
                prev =(st2.empty())? '0': st2.top();
            }
            else
            {
                st2.push(ch);
            }

            // PrintStack(st); cout<<endl;
            // PrintStack(st2); cout<<endl<<endl;
        }

        string res;
        while(!st2.empty())
        {
            res.push_back(st2.top()); st2.pop();
        }

        return res;
    }
};

int main()
{
    int t, k;
	cin>>t;
	Solution ob;
	string s;
	while(t--)
	{
        cin>>s>>k;
        cout<<ob.removeDuplicates(s, k)<<endl;
	}

    return 0;
}
