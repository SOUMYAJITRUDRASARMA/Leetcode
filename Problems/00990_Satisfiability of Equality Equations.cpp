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

    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        vector<int> v(26, -1), inequalityIndexes;
        for(int i=0;i<n;i++)
        {
            if(equations[i][1] == '!') inequalityIndexes.push_back(i);
            else unionDS(equations[i][0] - 'a', equations[i][3] - 'a', v);
        }

        for(int index: inequalityIndexes)
            if(findRep(equations[index][0] - 'a', v) == findRep(equations[index][3] - 'a', v)) return false;

        return true;
    }
};
