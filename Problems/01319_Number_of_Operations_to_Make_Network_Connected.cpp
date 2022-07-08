// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Number of connected components


class Solution {
public:
    void dfs(int cur, vector<vector<int>> &adj, vector<bool> &vis)
    {
        vis[cur] = true;
        for(int neighbour: adj[cur])
            if(!vis[neighbour])
                dfs(neighbour, adj, vis);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
            return -1;

        vector<vector<int>> adj(n);
        for(vector<int> &v: connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        int numComp = 0;
        vector<bool> vis(n, false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i]){ dfs(i, adj, vis); numComp++;}
        }

        return numComp-1;
    }
};
