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

    int minSwapsCouples(vector<int>& row) {
        // suppose n couples not matched, then n-1 swaps needed to match them [not necessarily] -> 0 1 1 2 2 0 [Here, 2 swaps needed]
        // lets try matching couples at even positions - 01 23 45 ... , then apply k-1 formula
        // even this wont directly work - 0 1 0 1 2 3 2 3  ->  2 (2-1 + 2-1) swaps are good (3 not needed)
        // so we need to find disjoint cycles and their lengths
        int n = (row.size() + 1) / 2, a, b;
        // vector<int> parent(n, -1);
        vector<int> dsu(n, -1); // lets use dsu to avoid confusion of direction of the edges for the cycle
        for(int i=0;i<n;i++)
        {
            a = row[2 * i] / 2, b = row[2 * i + 1] / 2;
            unionDS(a, b, dsu);
            // if(parent[a] == -1) parent[a] = b;
            // else parent[b] = a;
        }

        // Now like cycle length detection
        unordered_set<int> visNodes;
        int rep, ans = 0;
        for(int i=0;i<n;i++)
        {
            rep = findRep(i, dsu);
            if(visNodes.find(rep) == visNodes.end())
                visNodes.insert(rep), ans += - dsu[rep] - 1; // getting size - 1 = cycleLength - 1
        }

        return ans;

        /* vector<bool> vis(n, false);
        int ans = 0, cur, tmp;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                tmp = 0, vis[i] = true, cur = parent[i];
                while(!vis[cur]) vis[cur] = true, tmp++, cur = parent[cur];
                ans += tmp;
            }
        }

        return ans; */


        /* int cnt = 0, n = row.size();
        for(int i=0;i<n;i+=2) if(row[i] / 2 != row[i + 1] / 2) cnt++;
        return cnt - 1; */
    }
};
