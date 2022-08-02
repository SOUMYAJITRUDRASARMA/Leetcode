class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> lcs(n + 1, vector<int>(m + 1, 0)); // lowest common substring
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(s[i - 1] == t[j - 1])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;

        int cnt = 0, p, q, l, r;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(lcs[i][j] == 0)
                {
                    l = lcs[i - 1][j - 1];
                    r = 0;
                    p = i + 1, q = j + 1;
                    while(p <= n && q <= m && lcs[p][q] > 0) r++, p++, q++;

                    cnt += (l + 1) * (r + 1);
                }
            }
        }

        return cnt;
    }
};
