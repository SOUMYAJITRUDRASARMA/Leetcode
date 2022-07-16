class Solution {
public:
    inline bool canDetonate(vector<int> &src, vector<int> &dest)
    {
        long long dist = ((long long)(src[0] - dest[0])) * ((long long)(src[0] - dest[0])) +
                         ((long long)(src[1] - dest[1])) * ((long long)(src[1] - dest[1]));
        return dist <= ((long long)src[2]) * ((long long)src[2]);
    }

    int dfsCount(int cur, vector<vector<int>> &adj, vector<bool> &vis)
    {
        vis[cur] = true;

        int ans = 0;
        for(int neighbour: adj[cur])
            if(!vis[neighbour])
                ans += dfsCount(neighbour, adj, vis);

        // cannot set vis[cur] = false here on callback else it will see for all possible paths - ans will be more
        return 1 + ans;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == j) continue;

                if(canDetonate(bombs[i], bombs[j]))
                    adj[i].push_back(j);
            }
        }

        int MAX = INT_MIN;
        // vector<int> dp(n, -1); // -1 means not calculated // cannot apply dp here due to cycles
        vector<bool> vis(n, false);
        for(int i=0;i<n;i++)
        {
            MAX = max(MAX, dfsCount(i, adj, vis));
            fill(vis.begin(), vis.end(), false);
        }

        return MAX;
    }
};
