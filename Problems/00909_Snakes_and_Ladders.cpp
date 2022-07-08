class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // BFS
        int n = board.size(), x, y, curNumMoves, qSize, cur, cur2;
        vector<int> adj(n*n + 1);
        vector<bool> vis(n*n + 1, false);

        for(int i=1;i<=n*n;i++)
        {
            x = n-1 - (i-1)/n;
            y = ((n-1 - x) % 2 == 0)? ((i-1) % n): (n-1 - (i-1) % n);
            adj[i] = board[x][y];
        }

        // for(int i: adj) cout<<i<<" ";
        queue<int> q;
        q.push(1);
        curNumMoves = 0;
        while(!q.empty())
        {
            qSize = q.size();
            while(qSize--)
            {
                cur = q.front(); q.pop(); // cout<<"cur: "<<cur<<" Move: "<<curNumMoves<<endl;

                if(cur == n*n) return curNumMoves;
                for(int i=1;i<=6;i++)
                {
                cur2 = cur + i;
                if(cur2 <= n*n)
                {
                    /*if(!vis[cur2])
                    {
                        vis[cur2] = true;
                        if(adj[cur2] != -1)
                        {
                            cur2 = adj[cur2];
                            if(!vis[cur2])
                            {
                                vis[cur2] = true;
                                q.push(cur2);
                            }
                        }
                        else
                        {
                            q.push(cur2);
                        }
                    }*/
                    // TC :-
                    // [[-1,-1,-1,46,47,-1,-1,-1]
                    // ,[51,-1,-1,63,-1,31,21,-1]
                    // ,[-1,-1,26,-1,-1,38,-1,-1]
                    // ,[-1,-1,11,-1,14,23,56,57]
                    // ,[11,-1,-1,-1,49,36,-1,48]
                    // ,[-1,-1,-1,33,56,-1,57,21]
                    // ,[-1,-1,-1,-1,-1,-1,2,-1]
                    // ,[-1,-1,-1,8,3,-1,6,56]]
                    // Bottom of ladder might be reached by another ladder before, so if it is checked vis[] first, the top of 2nd ladder advantage will be ignored

                    if(adj[cur2] != -1)
                    {
                        cur2 = adj[cur2];
                        if(!vis[cur2])
                        {
                            vis[cur2] = true;
                            q.push(cur2);
                        }
                    }
                    else
                    {
                        if(!vis[cur2])
                        {
                            vis[cur2] = true;
                            q.push(cur2);
                        }
                    }
                }
                }
            }

            curNumMoves++;
        }

        return -1;
    }
};
