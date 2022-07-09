class Solution {
public:
    void dfs(int cur, int end, vector<int> &path, vector<vector<int>>& graph, vector<vector<int>> &ans)
    {
        path.push_back(cur);
        if(cur == end){ ans.push_back(path); path.pop_back(); return; }
        for(int neighbour: graph[cur]) dfs(neighbour, end, path, graph, ans);
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // DAG -> no cycles
        // so simple dfs without visited array will work
        // backtracking
        vector<vector<int>> ans;
        vector<int> path;
        int n = graph.size();
        dfs(0, n - 1, path, graph, ans);
        return ans;
    }
};
