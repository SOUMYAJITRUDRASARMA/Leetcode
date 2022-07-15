class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> adj(n); // fast finding of edges
        vector<int> degree(n, 0);
        for(vector<int> &road: roads)
        {
            degree[road[0]]++;
            degree[road[1]]++;
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }

        int MAX = INT_MIN, val;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                val = degree[i] + degree[j] - ((adj[i].find(j) != adj[i].end())? 1: 0);
                MAX = max(val, MAX);
            }
        }

        return MAX;
    }
};
