class Solution {
public:
    void helper(int cur, vector<vector<int>> &adj, vector<bool> &vis, vector<unordered_set<int>> &ancestor)
    {
        for(int neighbour: adj[cur])
        {
            if(!vis[neighbour])
                helper(neighbour, adj, vis, ancestor);

            for(int e: ancestor[neighbour])
                ancestor[cur].insert(e);

            ancestor[cur].insert(neighbour);
        }

        vis[cur] = true;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<int>> adj(n); // Reverse graph  -  a -> b means b is parent of a
        for(vector<int> &edge: prerequisites) adj[edge[1]].push_back(edge[0]);
        vector<bool> vis(n, false);
        vector<unordered_set<int>> ancestor(n); // to not have duplicates

        for(int i=0;i<n;i++)
            if(!vis[i])
                helper(i, adj, vis, ancestor);

        vector<bool> ans;
        for(vector<int> &query: queries)
            ans.push_back(ancestor[query[1]].find(query[0]) != ancestor[query[1]].end());

        return ans;
    }
};
