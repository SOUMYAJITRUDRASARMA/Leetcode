class Solution {
public:
    int helper(int cur, int mask, vector<vector<int>> &dp, vector<vector<int>>& graph)
    {
        if(dp[cur][mask]) return dp[cur][mask];
        if((mask & (mask - 1)) == 0) return 0; // only 1 node visited

        dp[cur][mask] = INT_MAX + 1; // avoid infinite loop in cycle, -1 for +1 later
        for(int neighbour: graph[cur])
        {
            if((mask & (1 << neighbour)) != 0)
            {
                // if neighbour is visited
                int alreadyVis = helper(neighbour, mask, dp, graph);
                int notVis = helper(neighbour, mask ^ (1 << cur), dp, graph);
                int better = min(alreadyVis, notVis);
                dp[cur][mask] = min(dp[cur][mask], 1 + better);
            }
        }

        return dp[cur][mask];
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int endingMask = (1 << n) - 1; // mask is vector<bool> of visited ndoes
        vector<vector<int>> dp(n + 1, vector<int>(endingMask + 1, 0)); // 0 means not found

        int MIN = INT_MAX;
        for(int i=0;i<n;i++)
            MIN = min(MIN, helper(i, endingMask, dp, graph));

        return MIN;
    }
};
