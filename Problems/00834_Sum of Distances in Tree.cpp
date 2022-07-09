class Solution {
public:
    int numNodesHelper(int cur, vector<int> &numNodes, vector<vector<int>> &adj)
    {
        int ans = 0;
        numNodes[cur] = 0;

        for(int neighbour: adj[cur])
            if(numNodes[neighbour] == -1) ans += numNodesHelper(neighbour, numNodes, adj);

        return numNodes[cur] = 1 + ans;
    }

    int bfs(vector<vector<int>> &adj, int n)
    {
        int sum = 0;
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        int e, curLvl = -1, qSize;
        while(!q.empty())
        {
            curLvl++, qSize = q.size(), sum += curLvl * qSize;
            while(qSize--)
            {
                e = q.front(); q.pop();
                vis[e] = true;
                for(int neighbour: adj[e])
                    if(!vis[neighbour]) q.push(neighbour);
            }
        }

        return sum;
    }

    void dfs(int cur, int parent, int n, vector<vector<int>> &adj, vector<int> &ans,vector<int> &numNodes)
    {
        // going inorder dfs, so that parent ans is calculated before child
        // ans[child] + #child = ans[parent] + #parent  =>  ans[child] = ans[parent] + #parent - #child
        // #parent = n - #child (dont take from array, as #parent in whole other tree, not just its subtree)
        ans[cur] = ans[parent] + (n - numNodes[cur]) - numNodes[cur];
        for(int neighbour: adj[cur])
            if(neighbour != parent) dfs(neighbour, cur, n, adj, ans, numNodes);
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int> &edge: edges)
            adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);

        // considering '0' as root
        vector<int> numNodes(n, -1); // keeps track of visited, -1 -> Unvisited, 0 -> visited
        numNodesHelper(0, numNodes, adj);

        // calculating the answer for '0' (root)
        vector<int> ans(n);
        ans[0] = bfs(adj, n);

        // calculating answer for others through dfs
        for(int neighbour: adj[0])
            dfs(neighbour, 0, n, adj, ans, numNodes);

        return ans;
    }
};
