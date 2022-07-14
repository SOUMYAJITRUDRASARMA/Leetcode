class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> hasEdgeInto(n, false);
        for(vector<int> &edge: edges) hasEdgeInto[edge[1]] = true;
        vector<int> ans;
        for(int i=0;i<n;i++) if(!hasEdgeInto[i]) ans.push_back(i);
        return ans;
    }
};
