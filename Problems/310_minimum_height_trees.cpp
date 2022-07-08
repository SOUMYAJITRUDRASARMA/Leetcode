#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MOD 1000000007


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // find leaves, remove till left with all remaining nodes are leaves
        // these remaining nodes are the required min tree root nodes

        vector<set<int>> adj(n); // adjacency list

        // building tree as graph
        for(vector<int> &v: edges)
        {
            adj[v[0]].insert(v[1]);
            adj[v[1]].insert(v[0]);
        }

        // for(set<int> s: adj){ for(int e: s) cout<<e<<"  "; cout<<endl; } // testing

        vector<bool> vis(n, false);
        vector<int> curLeaves;
        bool onlyLeavesLeft;
        while(true)
        {
            // for(set<int> s: adj){ for(int e: s) cout<<e<<"  "; cout<<endl; } // testing
            onlyLeavesLeft = true;
            curLeaves.clear();
            for(int i=0;i<n;i++)
            {
                if(vis[i])
                    continue;

                if(adj[i].size()<=1)
                    curLeaves.push_back(i);
                else
                    onlyLeavesLeft = false;
            }

            if(onlyLeavesLeft)
                break;

            for(int e: curLeaves)
            {
                vis[e] = true;
                for(int neighbour: adj[e])
                    adj[neighbour].erase(e);
                // e.clear(); // not needed, as e is visited true and no way to reach it now through other nodes ...
            }
        }

        return curLeaves;
    }
};

int main()
{
    vector<vector<int>> e(3);
    e[0].push_back(1);
    e[0].push_back(0);
    e[1].push_back(1);
    e[1].push_back(2);
    e[2].push_back(1);
    e[2].push_back(3);

    vector<int> root = (new Solution)->findMinHeightTrees(4,e);
    for(int e: root) cout<<e<<"  ";

    return 0;
}
