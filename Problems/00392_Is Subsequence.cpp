class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;

        int n = s.size(), cur = 0;
        for(char ch: t)
        {
            if(ch == s[cur]) cur++;
            if(cur == n) return true;
        }

        return false;
    }
};
