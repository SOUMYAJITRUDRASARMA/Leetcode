class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustedBy(n + 1, 0), doesTrust(n + 1, 0);
        for(vector<int> &v: trust) trustedBy[v[1]]++, doesTrust[v[0]]++;

        int townJudge = -1;
        for(int i=1;i<=n;i++)
        {
            if(trustedBy[i] == n - 1 && doesTrust[i] == 0)
            {
                if(townJudge == -1) townJudge = i;
                else return -1;
            }
        }

        return townJudge;
    }
};
