class Solution {
public:
    void helper(int cur, int n, int balScore, string &curStr, string &s, vector<string> &ans, int left, int right, unordered_set<string> &Set)
    {
        // balScore -> +ve for '(' and -ve for ')'
        // cout<<"cur: "<<cur<<", balScore: "<<balScore<<", curStr: "<<curStr<<", left: "<<left<<", right: "<<right<<endl;
        if(cur == n)
        {
            if(!left && !right && !balScore && Set.find(curStr) == Set.end()){ ans.push_back(curStr); Set.insert(curStr); }
            return;
        }

        if(s[cur] == '(')
        {
            curStr.push_back('(');
            helper(cur + 1 , n, balScore + 1, curStr, s, ans, left, right, Set);
            curStr.pop_back();

            if(left)
            {
                helper(cur + 1 , n, balScore, curStr, s, ans, left - 1, right, Set);
            }
        }
        else if(s[cur] == ')')
        {
            if(balScore)
            {
                curStr.push_back(')');
                helper(cur + 1 , n, balScore - 1, curStr, s, ans, left, right, Set);
                curStr.pop_back();
            }

            if(right)
            {
                helper(cur + 1 , n, balScore, curStr, s, ans, left, right - 1, Set);
            }
        }
        else
        {
            curStr.push_back(s[cur]);
            helper(cur + 1 , n, balScore, curStr, s, ans, left, right, Set);
            curStr.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0; // # misplaced left and right brackets
        for(char ch: s)
        {
            if(ch == '('){ left++; }
            else if(ch == ')'){ if(left) left--; else right++; }
        }

        vector<string> ans;
        int n = s.size();
        string curStr;
        unordered_set<string> Set;
        helper(0, n, 0, curStr, s, ans, left, right, Set);

        return ans;
    }
};
