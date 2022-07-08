bool compPair(vector<int> &p1, vector<int> &p2)
{
    if(p1[0] < p2[0]) return true;
    else if(p1[0] > p2[0]) return false;
    else return p1[1] < p2[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size(), MAX = 1;
        sort(pairs.begin(), pairs.end(), compPair);
        vector<int> dp(n, 1);

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }

            MAX = max(MAX, dp[i]);
        }

        return MAX;
    }
};
