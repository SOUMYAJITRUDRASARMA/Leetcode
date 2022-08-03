class Solution {
public:
    vector<vector<int>> dp;

    Solution(){ dp.resize(1001); for(vector<int> &v: dp) v.resize(3), fill(v.begin(), v.end(), -1); }

    int helper(int n, int k)
    {
        if(k == 1 || n < 2) return n;

        if(dp[n][k] != -1) return dp[n][k];

        int l = 1, h = n, m, MIN = INT_MAX;
        int eggBreak, eggNotBreak;
        while(l <= h)
        {
            m = (l + h) / 2;
            eggBreak = helper(m - 1, k - 1);
            eggNotBreak = helper(n - m, k);

            if(eggBreak < eggNotBreak) l = m + 1;
            else h = m - 1;

            MIN = min(MIN, 1 + max(eggBreak, eggNotBreak));
        }

        return dp[n][k] = MIN;
    }

    int twoEggDrop(int n) {
        // n floors, k eggs
        int k = 2;
        return helper(n, k);
    }
};
