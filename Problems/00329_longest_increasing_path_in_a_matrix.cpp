#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MOD 1000000007
// WATCH -->  https://www.youtube.com/watch?v=wCc_nd-GiEc

class Solution {
public:
    int dfsLIP(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& LIP, int m, int n)
    {
        int maxLen = 0;

        // UP
        if(i>0)
            if(matrix[i][j] > matrix[i-1][j])
                maxLen = max(maxLen, (LIP[i-1][j] == 0)? dfsLIP(i-1, j, matrix, LIP, m, n): LIP[i-1][j]);
        // LEFT
        if(j>0)
            if(matrix[i][j] > matrix[i][j-1])
                maxLen = max(maxLen, (LIP[i][j-1] == 0)? dfsLIP(i, j-1, matrix, LIP, m, n): LIP[i][j-1]);
        // DOWN
        if(i<m-1)
            if(matrix[i][j] > matrix[i+1][j])
                maxLen = max(maxLen, (LIP[i+1][j] == 0)? dfsLIP(i+1, j, matrix, LIP, m, n): LIP[i+1][j]);
        // RIGHT
        if(j<n-1)
            if(matrix[i][j] > matrix[i][j+1])
                maxLen = max(maxLen, (LIP[i][j+1] == 0)? dfsLIP(i, j+1, matrix, LIP, m, n): LIP[i][j+1]);

        LIP[i][j] = maxLen + 1;
        return maxLen + 1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> LIP(matrix.size(),vector<int>(matrix[0].size(),0)); // 0 means not processed yet
        int m = matrix.size();
        int n = matrix[0].size();
        int MAX = 1;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(LIP[i][j] == 0)
                    MAX = max(MAX, dfsLIP(i, j, matrix, LIP, m, n)); // run dfs if not visited , only start points of a DFS will have max path length
            }
        }

        return MAX;
    }
};

int main()
{
    vector<vector<int>> m(3);
    m[0] = vector<int>({9,9,4});
    m[1] = vector<int>({6,6,8});
    m[2] = vector<int>({2,1,1});

    cout<< (new Solution)->longestIncreasingPath(m) <<endl;
    return 1;
}
