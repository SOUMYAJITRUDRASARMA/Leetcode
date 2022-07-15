class Solution {
public:
    int findRep(int i, vector<int> &v)
    {
        if(v[i] < 0) return i;
        else return v[i] = findRep(v[i], v);
    }

    bool unionDS(int a, int b, vector<int> &v)
    {
        int aRep, bRep;
        aRep = findRep(a, v);
        bRep = findRep(b, v);

        if(aRep == bRep) return false;

        int aSize, bSize;
        aSize = -v[aRep];
        bSize = -v[bRep];

        if(aSize <= bSize)
        {
            v[aRep] = bRep;
            v[bRep] = -(aSize + bSize);
        }
        else
        {
            v[bRep] = aRep;
            v[aRep] = -(aSize + bSize);
        }

        return true;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> v(n, -1);
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    unionDS(i, j, v);
            }
        }

        int numSets = 0;
        for(int e: v) if(e < 0) numSets++;

        return n - numSets;
    }
};
