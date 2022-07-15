class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1); // 1 indexed nodes
        for(vector<int> &path: paths)
            adj[path[0]].push_back(path[1]), adj[path[1]].push_back(path[0]);

        /* vector<vector<bool>>(n, vector<bool>(5, true)); // colors available ?
        vector<int> color(n, -1);

        for() */

        vector<bool> available(5, true);
        vector<int> color(n, -1);

        // node coloring algorithm
        for(int i=1;i<=n;i++)
        {
            // marking all colors used by neighbours
            for(int neighbour: adj[i])
                if(color[neighbour-1] != -1)
                    available[color[neighbour-1]] = false;

            //finding any color that is available for use
            int col = -1;
            for(int j=1;j<available.size();j++)
            {
                if(available[j])
                {
                    col = j;
                    break;
                }
            }

            //coloring the node with the found available color
            color[i - 1] = col;

            //resetting the colors of the adj nodes to available
            for(auto &neighbour: adj[i])
            {
                if(color[neighbour-1]!= -1)
                    available[color[neighbour-1]] = true;
            }
        }

        return color;
    }
};
