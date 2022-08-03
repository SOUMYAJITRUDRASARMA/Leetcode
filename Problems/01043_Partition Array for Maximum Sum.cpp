class Solution {
public:
    int queryMax(int L, int R, vector<int> &arr, vector<vector<int>> &maxSparseTable)
    {
        int j = (int)log2(R - L + 1);
        if (maxSparseTable[L][j] >= maxSparseTable[R - (1 << j) + 1][j]) return maxSparseTable[L][j];
        else return maxSparseTable[R - (1 << j) + 1][j];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // Think dynamic programming: dp[i] will be the answer for array A[0], ..., A[i-1]
        // For j = 1 .. k that keeps everything in bounds, dp[i] is the maximum of dp[i-j] + max(A[i-1], ..., A[i-j]) * j
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        vector<vector<int>> maxSparseTable(n + 1, vector<int>(n + 1));
        for(int i=0;i<n;i++) maxSparseTable[i][0] = arr[i];
        for(int j=1;(1<<j)<=n;j++)
        {
            // Compute minimum value for all intervals with size 2^j
            for(int i=0;(i+(1<<j)-1)<n;i++)
            {
                if(maxSparseTable[i][j - 1] > maxSparseTable[i + (1 << (j - 1))][j - 1]) maxSparseTable[i][j] = maxSparseTable[i][j - 1];
                else maxSparseTable[i][j] = maxSparseTable[i + (1 << (j - 1))][j - 1];
            }
        }

        for(int i=1;i<=n;i++)
        {
            // for(int j=i-1;j>=max(0, i - k);j--) dp[i] = max(dp[i], dp[j] + queryMax(j, i - 1, arr, maxSparseTable) * (i - j));
            for(int j=1;j<=k && i-j>=0;j++) dp[i] = max(dp[i], dp[i - j] + queryMax(i - j, i - 1, arr, maxSparseTable) * j);
        }

        return dp[n];
    }
};
