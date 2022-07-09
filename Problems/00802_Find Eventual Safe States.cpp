class Solution {
public:
    bool isSafe(int cur, vector<bool> &inCurPath, vector<vector<int>>& graph, unordered_map<int, bool> &dp)
    {
        if(dp.find(cur) != dp.end()) return dp[cur];

        if(inCurPath[cur]) return dp[cur] = false;

        inCurPath[cur] = true;
        for(int neighbour: graph[cur]) if(!isSafe(neighbour, inCurPath, graph, dp)) return dp[cur] = false;
        inCurPath[cur] = false;

        return dp[cur] = true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, bool> dp;
        vector<bool> inCurPath(n, false);

        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(isSafe(i, inCurPath, graph, dp)) ans.push_back(i);
            fill(inCurPath.begin(), inCurPath.end(), false);
        }
        return ans;
    }
};
