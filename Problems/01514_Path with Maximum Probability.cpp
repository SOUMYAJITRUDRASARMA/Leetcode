class Solution {
public:
    void dijkstra(int V, vector<vector<pair<int, double>>> adj, int S, int E, vector<double> &dist)
    {
        // Code here
        vector<bool> vis(V, false);
        // vector<int> dist(V);
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq; // weight, node
        pq.push(make_pair(0, S));

        pair<double, int> p;
        int cnt = 0;
        while(!pq.empty())
        {
            p = pq.top(); pq.pop();
            if(vis[p.second]) continue;

            vis[p.second] = true;
            dist[p.second] = p.first;
            cnt++;
            if(cnt == V || p.second == E) break;

            for(pair<int, double> &neighbour: adj[p.second])
                if(!vis[neighbour.first])
                    pq.push(make_pair(dist[p.second] + neighbour.second, neighbour.first));
        }
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(make_pair(edges[i][1], -log2(succProb[i]))); // -log for dijkstra  -  prob is (0, 1) so log is -ve, so -log is +ve
            adj[edges[i][1]].push_back(make_pair(edges[i][0], -log2(succProb[i])));
        }

        vector<double> dist(n, -1); // -1 means not found, cannot support INF
        dijkstra(n, adj, start, end, dist);
        return (dist[end] != -1)? pow(2, -dist[end]): 0;
    }
};
