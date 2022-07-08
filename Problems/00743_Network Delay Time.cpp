class Solution {
public:
    vector <int> dijkstra(int V, vector<vector<pair<int, int>>> &adj, int S)
    {
        // Code here
        vector<bool> vis(V, false);
        vector<int> dist(V, INT_MAX);
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

            for(pair<int, int> &neighbour: adj[p.second])
                if(!vis[neighbour.first])
                    pq.push(make_pair(dist[p.second] + neighbour.second, neighbour.first));
        }

        return dist;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(vector<int> &edge: times) adj[edge[0] - 1].push_back(make_pair(edge[1] - 1, edge[2])); // 1 indexed

        vector<int> dist = dijkstra(n, adj, k - 1); // 1 indexed
        int MAX = *max_element(dist.begin(), dist.end());
        return (MAX == INT_MAX)? -1: MAX;
    }
};
