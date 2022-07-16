class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // BFS
        vector<vector<int>> red_graph(n), blue_graph(n);

        for(auto &i : redEdges)
            red_graph[i[0]].push_back(i[1]);

        for(auto &i : blueEdges)
            blue_graph[i[0]].push_back(i[1]);

        // Djikstra's BFS
        vector<int> distr(n, INT_MAX), distb(n, INT_MAX);
        distr[0] = distb[0] = 0;

        queue<pair<int, char>> q;
        q.push({0, '\0'});

        while(!q.empty())
        {
            auto tmp = q.front();
            q.pop();

            if(tmp.second != 'r')
                for(auto &i : red_graph[tmp.first])
                    if(distr[i] > distb[tmp.first] + 1)
                        distr[i] = distb[tmp.first] + 1, q.push({i, 'r'});

            if(tmp.second != 'b')
                for(auto &i : blue_graph[tmp.first])
                    if(distb[i] > distr[tmp.first] + 1)
                        distb[i] = distr[tmp.first] + 1, q.push({i, 'b'});
        }

        for(int i = 0; i < n; i++)
        {
            distr[i] = min(distr[i], distb[i]);

            if(distr[i] == INT_MAX)
                distr[i] = -1;
        }

        return distr;


        /* vector<vector<pair<int, bool>>> adj(n); // neighbour, isRed
        for(vector<int> &edge: redEdges) adj[edge[0]].push_back(make_pair(edge[1], true));
        for(vector<int> &edge: blueEdges) adj[edge[0]].push_back(make_pair(edge[1], false));

        vector<int> dist(n, -1); // -1 means not visited
        dist[0] = 0;
        queue<pair<int, bool>> q; // node and prev color of edge taken */

    }
};
