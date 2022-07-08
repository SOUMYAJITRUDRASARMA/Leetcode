// https://leetcode.com/problems/find-if-path-exists-in-graph/


class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int source, int destination, vector<bool> &vis)
    {
        if(source == destination)
            return true;

        vis[source] = true;
        for(int e: adj[source])
            if(!vis[e])
                if(dfs(adj, e, destination, vis))
                    return true;

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for(vector<int> &v: edges){ adj[v[0]].push_back(v[1]); adj[v[1]].push_back(v[0]); }
        return dfs(adj, source, destination, vis);
    }
};
