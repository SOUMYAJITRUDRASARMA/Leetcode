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

    double dfs(int cur, int e, double val, double &ansVal, vector<bool> &vis, vector<vector<pair<int, double>>> &adj)
    {
        vis[cur] = true;
        if(cur == e){ ansVal = val; return true; }

        for(pair<int, double> p: adj[cur])
            if(!vis[p.first] && dfs(p.first, e, val * p.second, ansVal, vis, adj)) return true;

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> m;
        int cnt = 0, n = equations.size();
        string a, b;
        vector<vector<pair<int, double>>> adj;
        vector<int> ds(40, -1); // for union find | max 20 equations
        for(int i=0;i<n;i++)
        {
            a = equations[i][0], b = equations[i][1];
            if(m.find(a) == m.end()) m[a] = cnt++, adj.push_back(vector<pair<int, double>>());
            if(m.find(b) == m.end()) m[b] = cnt++, adj.push_back(vector<pair<int, double>>());

            adj[m[a]].push_back(make_pair(m[b], values[i]));
            adj[m[b]].push_back(make_pair(m[a], 1 / values[i]));

            if(findRep(m[a], ds) != findRep(m[b], ds)) unionDS(m[a], m[b], ds);
        }

        vector<double> ans;
        int s, e;
        double ansVal;
        for(vector<string> &query: queries)
        {
            a = query[0], b = query[1];
            if(m.find(a) == m.end()){ ans.push_back(-1.0); continue; }
            if(m.find(b) == m.end()){ ans.push_back(-1.0); continue; }

            s = m[a], e = m[b];
            if(findRep(s, ds) != findRep(e, ds)){ ans.push_back(-1.0); continue; }

            // DFS
            vector<bool> vis(cnt, false);
            dfs(s, e, 1.0, ansVal, vis, adj);
            ans.push_back(ansVal);
        }

        return ans;
    }
};
