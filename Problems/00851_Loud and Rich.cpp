class Solution {
public:
    int helper(int cur, vector<vector<int>> &adj, vector<int>& quiet, vector<int> &ans)
    {
        if(ans[cur] != -1) return ans[cur];

        int res = cur, e;
        for(int neighbour: adj[cur])
        {
            e = helper(neighbour, adj, quiet, ans);
            if(quiet[e] <= quiet[res]) res = e;
        }

        return ans[cur] = res;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n); // adjacency graph of richer, a -> b means b is richer than a
        for(vector<int> &v: richer) adj[v[1]].push_back(v[0]);

        vector<int> ans(n, -1); // dp array
        for(int i=0;i<n;i++) if(ans[i] == -1) helper(i, adj, quiet, ans);

        return ans;
    }
};
