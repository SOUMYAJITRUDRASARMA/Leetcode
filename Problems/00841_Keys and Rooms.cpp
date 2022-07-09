class Solution {
public:
    void dfs(int cur, vector<vector<int>> &adj, vector<bool> &vis)
    {
        vis[cur] = true;
        for(int neighbour: adj[cur])
            if(!vis[neighbour]) dfs(neighbour, adj, vis);
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(0, roms, vis);
        for(bool e: vis) if(!e) return false;
        return true;
    }
};
