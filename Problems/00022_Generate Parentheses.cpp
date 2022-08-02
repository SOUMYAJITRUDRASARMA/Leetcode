class Solution {
public:
    vector<vector<string>> dp;

    Solution(){ dp.resize(9); dp[0].push_back(""); }

    vector<string> generateParenthesis(int n) {
        if(!dp[n].empty()) return dp[n];

        for(int i=0;i<n;i++)
            for(string left: generateParenthesis(i))
                for(string right: generateParenthesis(n - 1 - i))
                    dp[n].push_back("(" + left + ")" + right);

        return dp[n];
    }
};
