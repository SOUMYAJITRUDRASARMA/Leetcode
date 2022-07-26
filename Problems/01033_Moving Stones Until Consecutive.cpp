class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v( {a, b, c} );
        sort(v.begin(), v.end());
        a = v[0], b = v[1], c = v[2];
        bool b1 = (b - a == 1), b2 = (c - b == 1);

        int MIN, MAX;

        if(b1 && b2) MIN = 0;
        else if(!b1 && b2) MIN = 1;
        else if(b1 && !b2) MIN = 1;
        else
        {
            if(b - a == 2 || c - b == 2) MIN = 1;
            else MIN = 2;
        }

        MAX = (b - a - 1) + (c - b - 1);

        return {MIN, MAX};
    }
};
