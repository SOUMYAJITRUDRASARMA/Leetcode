class Solution {
public:
    struct Interval
    {
        int start;
        int end;
        Interval(int s, int e){ start = s; end = e; }
    };

    struct MyComp
    {
        bool operator () (Interval &i1, Interval &i2)
        {
            if(i1.start > i2.start) return true;
            else if(i1.start < i2.start) return false;
            else return i1.end > i2.end;
        }
    };

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<Interval, vector<Interval>, MyComp> pq;
        vector<vector<int>> ans;
        for(vector<int> &v: intervals) pq.push(Interval(v[0], v[1]));

        Interval cur(0, 0), i(0, 0);
        cur = pq.top(); pq.pop();
        while(!pq.empty())
        {
            i = pq.top(); pq.pop();
            if(i.start < cur.end) cur.end = max(cur.end, i.end);
            else
            {
                ans.push_back(vector<int>( { cur.start, cur.end } ));
                cur = i;
            }
        }

        return ans;
    }
};
