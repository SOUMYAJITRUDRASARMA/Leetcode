// https://leetcode.com/problems/find-center-of-star-graph/


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        set<int> s;
        s.insert(edges[0][0]);
        s.insert(edges[0][1]);

        return (s.find(edges[1][0]) != s.end())? edges[1][0]: edges[1][1];
    }
};
