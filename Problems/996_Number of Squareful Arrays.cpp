// https://leetcode.com/problems/number-of-squareful-arrays/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<long long, bool> m;
public:
    bool isSquare(long long num)
    {
        if(m.find(num) != m.end()) return m[num];

        long long a = (long long)sqrt<long long>(num);
        return m[num] = (a * a == num);
    }

    int numSquarefulPerms(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> graph(N); // undirected graph

        for(int i=0;i<N-1;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(isSquare((long long)nums[i] + (long long)nums[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        // Initialize a dp array
        int dp[N][(1 << N)];

        // Initialize it with 0
        memset(dp, 0, sizeof dp);

        // Initialize for the first vertex
        dp[0][1] = 1;

        // Iterate over all the masks
        for (int i = 2; i < (1 << N); i++) {

            // If the first vertex is absent
            if ((i & (1 << 0)) == 0)
            continue;

            // Only consider the full subsets
            if ((i & (1 << (N - 1)))
                && i != ((1 << N) - 1))
                continue;

            // Choose the end city
            for (int end = 0; end < N; end++) {

                // If this city is not in the subset
                if (i & (1 << end) == 0)
                    continue;

                // Set without the end city
                int prev = i - (1 << end);

                // Check for the adjacent cities
                for (int it : graph[end]) {
                    if ((i & (1 << it))) {
                        dp[end][i] += dp[it][prev];
                    }
                }
            }
        }

        // Return the answer
        return dp[N - 1][(1 << N) - 1];
    }
};

// without dp and bit-mask --> TLE
/* class Solution {
    unordered_map<long long, bool> m;
public:
    bool isSquare(long long num)
    {
        if(m.find(num) != m.end()) return m[num];

        long long a = (long long)sqrt<long long>(num);
        return m[num] = (a * a == num);
    }

    void dfs(int cur, int cnt, int n, vector<vector<int>> &adj, vector<bool> &vis, int &numHP)
    {
        if(cnt == n) numHP++;

        vis[cur] = true;
        for(int neighbour: adj[cur]) if(!vis[neighbour]) dfs(neighbour, cnt + 1, n, adj, vis, numHP);

        vis[cur] = false;
    }

    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> adj(n); // undirected graph

        unordered_map<int, int> freq;
        for(int i=0;i<n-1;i++)
        {
            freq[nums[i]]++;
            for(int j=i+1;j<n;j++)
            {
                if(isSquare((long long)nums[i] + (long long)nums[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        freq[nums[n - 1]]++;

        int numHP = 0;
        vector<bool> vis(n, false);
        for(int i=0;i<n;i++) dfs(i, 1, n, adj, vis, numHP);

        // for repeated same elements
        vector<long long> FACT(13, 1);
        for(int i=2;i<=12;i++) FACT[i] = FACT[i - 1] * i;
        for(pair<int, int> p: freq) numHP /= FACT[p.second];

        return numHP;
    }
}; */
