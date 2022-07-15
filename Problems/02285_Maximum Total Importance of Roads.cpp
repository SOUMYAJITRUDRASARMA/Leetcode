class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0); // degree of cities (nodes)
        for(vector<int> &road: roads) degree[road[0]]++, degree[road[1]]++;
        sort(degree.begin(), degree.end()); // ascending order
        long long ans = 0;
        for(int i=n-1;i>=0;i--) ans += ((long long)(i + 1)) * ((long long)degree[i]);
        return ans;
    }
};
