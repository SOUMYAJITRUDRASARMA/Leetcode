class Solution {
public:
    bool helper(int cur, bool curRed, vector<vector<int>>& graph, vector<char> &color)
    {
        // dfs
        if(color[cur] != 'N') return (color[cur] == 'R' && curRed) || (color[cur] == 'B' && !curRed);

        color[cur] = (curRed)? 'R': 'B';
        for(int neighbour: graph[cur])
            if(!helper(neighbour, !curRed, graph, color)) return false;

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<char> color(n, 'N'); // 'N' -> not assigned, 'R' -> red, 'B' -> blue
        for(int i=0;i<n;i++)
            if(color[i] == 'N' && !helper(i, true, graph, color)) return false;

        return true;
    }
};
