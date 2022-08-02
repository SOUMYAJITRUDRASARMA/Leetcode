class Solution {
public:
    vector<vector<int>> dp; // dp[n][char_no] -> ending with char 'a', 'e', 'i', 'o', 'u' (0 - 4)

    Solution(){ dp.resize(51); for(vector<int> &v: dp){ v.resize(5); fill(v.begin(), v.end(), -1); } for(int &e: dp[0]) e = 0; for(int &e: dp[1]) e = 1; }

    int helper(int n, int charNo)
    {
        if(dp[n][charNo] != -1) return dp[n][charNo];

        int sum = 0;
        for(int i=0;i<=charNo;i++) sum += helper(n - 1, i);

        return dp[n][charNo] = sum;
    }

    int countVowelStrings(int n) {
        int sum = 0;
        for(int i=0;i<5;i++) sum += helper(n, i);
        return sum;
    }
};
