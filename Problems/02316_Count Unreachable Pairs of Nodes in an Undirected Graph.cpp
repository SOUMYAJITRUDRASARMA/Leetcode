class Solution {
public:
    void dfs(int cur, vector<vector<int>> &adj, vector<bool> &vis, long long &cnt)
    {
        cnt++;
        vis[cur] = true;
        for(int neighbour: adj[cur])
            if(!vis[neighbour])
                dfs(neighbour, adj, vis, cnt);
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int> &edge: edges)
            adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);

        long long cnt;
        // vector<long long> numNodesInComp;
        long long ans = 0;
        vector<bool> vis(n, false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt = 0;
                dfs(i, adj, vis, cnt);
                // numNodesInComp.push_back(cnt);
                ans += cnt * (n - cnt);
            }
        }

        return ans / 2; // double counting of pairs and self pairs don't exist
    }
};
