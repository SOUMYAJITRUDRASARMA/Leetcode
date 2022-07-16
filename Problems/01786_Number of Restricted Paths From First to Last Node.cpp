class Solution {
    const long long MOD = 1e9 + 7;
public:
    void dijkstra(int V, vector<vector<vector<int>>> &adj, int S, vector<int> &dist)
    {
        // Code here
        vector<bool> vis(V + 1, false);
        // vector<int> dist(V);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // weight, node
        pq.push(make_pair(0, S));

        pair<int, int> p;
        int cnt = 0;
        while(!pq.empty())
        {
            p = pq.top(); pq.pop();
            if(vis[p.second]) continue;

            vis[p.second] = true;
            dist[p.second] = p.first;
            cnt++;
            if(cnt == V) break;

            for(vector<int> &neighbour: adj[p.second])
                if(!vis[neighbour[0]])
                    pq.push(make_pair(dist[p.second] + neighbour[1], neighbour[0]));
        }
    }

    long long helper(int cur, int end, vector<vector<vector<int>>> &adj, vector<int> &dist, vector<long long> &dp)
    {
        // adj with condition is a DAG
        if(dp[cur] != -1) return dp[cur];

        long long ans = 0;
        for(vector<int> &neighbour: adj[cur])
            if(dist[neighbour[0]] < dist[cur])
                ans = (ans + helper(neighbour[0], end, adj, dist, dp)) % MOD;

        return dp[cur] = ans;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n + 1);
        for(vector<int> &edge: edges)
            adj[edge[0]].push_back(vector<int>( {edge[1], edge[2]} )), adj[edge[1]].push_back(vector<int>( {edge[0], edge[2]} ));

        vector<int> dist(n + 1, INT_MAX);
        dijkstra(n, adj, n, dist);

        if(dist[1] == INT_MAX) return 0;

        vector<long long> dp(n + 1, -1); // -1 means not found
        dp[n] = 1;
        return helper(1, n, adj, dist, dp);
    }
};
