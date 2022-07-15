class Solution {
public:
    void helper(int cur, vector<vector<int>> &adj, vector<bool> &vis, vector<vector<int>> &ancestor, vector<unordered_set<int>> &ancestorHelper)
    {
        for(int neighbour: adj[cur])
        {
            if(!vis[neighbour])
                helper(neighbour, adj, vis, ancestor, ancestorHelper);

            for(int e: ancestor[neighbour])
                if(ancestorHelper[cur].find(e) == ancestorHelper[cur].end())
                    ancestor[cur].push_back(e), ancestorHelper[cur].insert(e);
            if(ancestorHelper[cur].find(neighbour) == ancestorHelper[cur].end())
            {
                ancestor[cur].push_back(neighbour);
                ancestorHelper[cur].insert(neighbour);
            }
        }

        vis[cur] = true;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n); // Reverse graph  -  a -> b means b is parent of a
        for(vector<int> &edge: edges) adj[edge[1]].push_back(edge[0]);
        vector<bool> vis(n, false);
        vector<vector<int>> ancestor(n);
        vector<unordered_set<int>> ancestorHelper(n); // to not have duplicates

        for(int i=0;i<n;i++)
            if(!vis[i])
                helper(i, adj, vis, ancestor, ancestorHelper);

        for(vector<int> &v: ancestor) sort(v.begin(), v.end());

        return ancestor;
    }
};
