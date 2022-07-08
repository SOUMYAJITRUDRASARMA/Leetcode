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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(), a, b; // given
        vector<int> v(n + 1, -1);

        for(vector<int> &edge: edges)
        {
            a = edge[0], b = edge[1];
            if(findRep(a, v) != findRep(b, v)) unionDS(a, b, v);
            else return edge;
        }

        return(vector<int>(1, 1));
    }
};
