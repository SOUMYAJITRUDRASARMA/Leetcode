class Solution {
public:
    void dfs(int cur, int parent, int &curTime, vector<int> &timeIn, vector<int> &low, vector<bool> &vis, vector<vector<int>> &adj, vector<vector<int>> &bridges)
    {
        vis[cur] = true;
        timeIn[cur] = low[cur] = curTime++;
        for(int neighbour: adj[cur])
        {
            if(neighbour == parent) continue;
            if(vis[neighbour]) low[cur] = min(low[cur], low[neighbour]);
            else
            {
                dfs(neighbour, cur, curTime, timeIn, low, vis, adj, bridges);
                low[cur] = min(low[cur], low[neighbour]);
                if(low[neighbour] > timeIn[cur])
                bridges.push_back(vector<int>( { cur, neighbour } ));
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // find all bridges
        // undirected graph
        vector<vector<int>> adj(n);
        for(vector<int> &c: connections)
            adj[c[0]].push_back(c[1]), adj[c[1]].push_back(c[0]);

        int curTime = 0;
        vector<int> timeIn(n, -1), low(n, -1);
        vector<bool> vis(n, false);

        // We have a connected graph, so no need of dfs-ing every node, 1 will visit all
        vector<vector<int>> bridges;
        dfs(0, -1, curTime, timeIn, low, vis, adj, bridges); // -1 as unknown parent

        return bridges;
    }
};
