class Solution {
public:
    vector<int> dp;

    Solution(){ dp.resize(50); fill(dp.begin(), dp.end(), -1); dp[0] = dp[1] = 1; }

    int climbStairs(int n) {
        if(dp[n] != -1) return dp[n];
        else return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};
