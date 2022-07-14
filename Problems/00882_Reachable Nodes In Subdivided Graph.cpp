class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // Dijkstra
        // for each (directed) edge (node, nei), we'll keep track of how many "new" nodes (new from subdivision of the original edge) were used. At the end, we'll sum up the utilization of each edge.
        vector<vector<pair<int, int>>> adj(n); // undirected weighted graph - dest, weight
        for(vector<int> &edge: edges)
            adj[edge[0]].push_back(make_pair(edge[1], edge[2])), adj[edge[1]].push_back(make_pair(edge[0], edge[2]));
        // ignore // edge[2] + 1 because after that many moves, we will reach that node

        map<int, int> dist;
        dist[0] = 0;
        for (int i = 1; i < n; ++i)
            dist[i] = maxMoves+1;

        map<pair<int, int>, int> used;
        int ans = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            pair<int, int> top = pq.top();
            pq.pop();
            int d = top.first, node = top.second;
            if (d > dist[node]) continue;

            // Each node is only visited once.  We've reached
            // a node in our original graph.
            ans++;

            for (auto pair: adj[node]) {
                // maxMoves - d is how much further we can walk from this node;
                // weight is how many new nodes there are on this edge.
                // v is the maximum utilization of this edge.
                int nei = pair.first;
                int weight = pair.second;
                used[{node, nei}] = min(weight, maxMoves - d);

                // d2 is the total distance to reach 'nei' (neighbor) node
                // in the original graph.
                int d2 = d + weight + 1;
                if (d2 < min(dist[nei], maxMoves+1)) {
                    pq.push({d2, nei});
                    dist[nei] = d2;
                }
            }
        }

        // At the end, each edge (u, v, w) can be used with a maximum
        // of w new nodes: a max of used[u, v] nodes from one side,
        // and used[v, u] nodes from the other.
        for (vector<int> edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            ans += min(w, used[{u, v}] + used[{v, u}]);
        }
        return ans;
    }
};
