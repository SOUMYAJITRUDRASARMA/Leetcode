class Solution {
public:
    void dfs(int cur, int n, vector<bool> &vis, vector<vector<int>>& isConnected)
    {
        vis[cur] = true;

        for(int i=0;i<n;i++) if(!vis[i] && isConnected[cur][i]) dfs(i, n, vis, isConnected);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // isConnected is adjacency matrix - undirected graph
        int cnt = 0, n = isConnected.size();
        vector<bool> vis(n, false);

        for(int i=0;i<n;i++)
        {
            if(!vis[i]) dfs(i, n, vis, isConnected), cnt++;
        }

        return cnt;
    }
};
