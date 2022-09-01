class Solution {
public:
    struct myComp
    {
        bool operator () (pair<int, int> p1, pair<int, int> p2)
        {
            return p1.first > p2.first;
        }
    };

    int minTaps(int n, vector<int>& ranges) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
        for(int i=0;i<=n;i++) pq.push(make_pair(max(0, i - ranges[i]), min(n, i + ranges[i])));

        if(pq.empty() || pq.top().first > 0) return -1;
        pair<int, int> p;
        int cnt = 0, cur = 0, MAX = INT_MIN;
        while(!pq.empty())
        {
            p = pq.top(); pq.pop();
            if(p.first > cur)
            {
                cnt++;
                if(p.first > MAX) return -1;
                cur = MAX;
                MAX = p.second;
            }
            else
            {
                MAX = max(MAX, p.second);
            }

            if(MAX == n){ cnt++; break; }
        }

        if(MAX < n) return -1;
        else return cnt;
    }
};
