class Solution {
    vector<string> dp;
public:
    Solution(){ dp = vector<string>(31); dp[1] = string("1"); }

    string countAndSay(int n) {
        if(!dp[n].empty()) return dp[n];

        string st = countAndSay(n - 1), ans;
        char cur = st[0], cnt = 0;
        for(char ch: st)
        {
            if(cur == ch)
            {
                cnt++;
            }
            else
            {
                ans.push_back(cnt + '0');
                ans.push_back(cur);
                cur = ch;
                cnt = 1;
            }
        }

        ans.push_back(cnt + '0');
        ans.push_back(cur);

        return dp[n] = ans;
    }
};
