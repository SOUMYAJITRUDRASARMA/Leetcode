class Solution {
public:
    #define ll long long
    #define pi pair<ll, ll>
    const int mod = 1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pi> adj[n];
        for(auto &e : roads){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        priority_queue<pi, vector<pi>, greater<pi>> minh;
        minh.push({0, 0});
        vector<ll> dist(n, LONG_MAX), way(n, 0);
        dist[0] = 0, way[0] = 1;
        while(!minh.empty()){
            auto node = minh.top(); minh.pop();
            ll u = node.second;
            if(node.first > dist[u]) continue;
            for(auto &e : adj[u]){
                ll v = e.first;
                ll w = e.second;
                if(dist[v] == w + dist[u]){
                    // cout<<way[u]<<" "<<endl;
                    way[v] = (way[v] + way[u]) % mod;
                }
                else if(dist[v] > w + dist[u]){
                    dist[v] = w + dist[u];
                    way[v] = way[u];
                    minh.push({dist[v], v});
                }
            }
        }
        // for(auto e : dist) cout<<e<<" ";
        return way[n - 1] % mod;
    }

    /* struct node
    {
        int cur, parent, weight;
        node(int c, int p, int w){ cur = c, parent = p, weight = w; }
    };

    struct greaterNodeComp
    {
        bool operator () (node &n1, node &n2)
        {
            return n1.weight > n2.weight;
        }
    };

    void dijkstra(int V, vector<vector<vector<int>>> &adj, int S, vector<int> &dist, vector<unordered_set<int>> &dag)
    {
        // Code here
        vector<bool> vis(V, false);
        // vector<int> dist(V);
        priority_queue<node, vector<node>, greaterNodeComp> pq; // weight, node
        pq.push( {S, -1, 0} );

        node p(0, 0, 0);
        // int cnt = 0; // because we need all possible paths in DAG
        while(!pq.empty())
        {
            p = pq.top(); pq.pop();
            if(vis[p.cur] && dist[p.cur] < p.weight) continue;

            if(p.parent != -1) dag[p.parent].insert(p.cur);
            vis[p.cur] = true;
            dist[p.cur] = p.weight;
            // cnt++;
            // if(cnt == V) break;

            for(vector<int> &neighbour: adj[p.cur])
                if(!vis[neighbour[0]])
                    pq.push( {neighbour[0], p.cur, dist[p.cur] + neighbour[1]} );
        }
    }

    int findNumPaths(int cur, int dest, vector<unordered_set<int>> &dag, vector<bool> &vis, vector<int> &dp)
    {
        if(cur == dest) return 1;
        if(dp[cur] != -1) return dp[cur];

        vis[cur] = true;
        int cnt = 0;
        for(int neighbour: dag[cur])
            if(!vis[neighbour])
                cnt += findNumPaths(neighbour, dest, dag, vis, dp);
        vis[cur] = false;

        return dp[cur] = cnt;
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>> adj(n);
        for(vector<int> &road: roads)
        {
            adj[road[0]].push_back( {road[1], road[2]} );
            adj[road[1]].push_back( {road[0], road[2]} );
        }

        vector<unordered_set<int>> dag(n); // new dag from shortest path edges // unoredered_set because multiple insertions in dijkstra
        vector<int> dist(n, INT_MAX);
        dijkstra(n, adj, 0, dist, dag);

        if(dist[n - 1] == INT_MAX) return 0;

        vector<bool> vis(n, false);
        vector<int> dp(n, -1);
        return findNumPaths(0, n - 1, dag, vis, dp);
    } */
};
