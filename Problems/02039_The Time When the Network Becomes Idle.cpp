class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        // BFS - Shortest Path
        int n = patience.size();
        vector<vector<int>> adj(n);
        for(vector<int> &edge: edges)
            adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);

        vector<int> dist(n, -2); // -2 works as not visited
        dist[0] = -1;
        queue<int> q;
        q.push(0);
        int cnt = 0, qSize, e;
        while(!q.empty())
        {
            qSize = q.size();
            while(qSize--)
            {
                e = q.front(); q.pop();
                dist[e] = cnt;
                for(int neighbour: adj[e])
                    if(dist[neighbour] == -2) dist[neighbour] = -1, q.push(neighbour);
            }
            cnt++;
        }

        int MAX = INT_MIN, time, RTT, lastTrTime;
        for(int i=1;i<n;i++)
        {
            // 2 * dist[i] should be total round-about trip time
            RTT = 2 * dist[i];
            if(RTT <= patience[i]) time = RTT;
            else
            {
                lastTrTime = RTT - (RTT % patience[i]);
                if(lastTrTime == RTT) lastTrTime -= patience[i];
                time = lastTrTime + RTT;
            }

            MAX = max(MAX, time + 1); // second '0' is also considered as a time
        }

        return MAX;
    }
};
