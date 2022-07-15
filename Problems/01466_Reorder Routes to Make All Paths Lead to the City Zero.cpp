class Solution {
public:
    struct hashFunction
    {
        size_t operator()(const pair<int, int> &x) const
        {
            return x.first ^ x.second;
        }
    };

    int minReorder(int n, vector<vector<int>>& connections) {
        // BFS
        vector<vector<int>> adj(n);
        unordered_set<pair<int, int>, hashFunction> s; // set for original edges
        for(vector<int> &conn: connections)
        {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
            s.insert( {conn[0], conn[1]} );
        }

        queue<int> q;
        q.push(0);
        vector<int> vis(n, false); // vis means in queue
        vis[0] = true;
        int ans = 0, e;
        while(!q.empty())
        {
            e = q.front(); q.pop();
            for(int neighbour: adj[e])
            {
                if(!vis[neighbour])
                {
                    q.push(neighbour);
                    vis[neighbour] = true;
                    if(s.find( {neighbour, e} ) == s.end()) ans++; // if reverse path is not found
                }
            }
        }

        return ans;
    }
};
