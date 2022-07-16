class Solution {
public:
    bool isBipartite(int cur, bool isCurRed, vector<vector<int>> &adj, unordered_map<int, bool> &isRed)
    {
        isRed[cur] = isCurRed;

        for(int neighbour: adj[cur])
        {
            if(isRed.find(neighbour) == isRed.end())
            {
                if(!isBipartite(neighbour, !isCurRed, adj, isRed))
                    return false;
            }
            else
            {
                if(isRed[neighbour] == isRed[cur])
                    return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for(vector<int> &edge: dislikes)
            adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);
        // although dislike maynot be undirected, but putting in different groups is

        unordered_map<int, bool> isRed;
        for(int i=1;i<=n;i++)
            if(isRed.find(i) == isRed.end())
                if(!isBipartite(i, true, adj, isRed))
                    return false;

        return true;
    }
};
